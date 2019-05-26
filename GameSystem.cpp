#include <iostream>

#include "GameSystem.h"
#include "Utils.h"

/**
 * Initialises the state of this object.
 */
GameSystem::GameSystem(std::string name, std::string version) {
	this->name = name;
	this->version = version;
	loadedGame = NULL;
	running = false;
	commandSystem = new CommandSystem();
}

/**
 * Gets the game system's name.
 */
std::string GameSystem::getName() {
	return name;
}

/**
 * Gets the game system's version.
 */
std::string GameSystem::getVersion() {
	return version;
}

/**
 * Flags the game system as running.
 * 
 * While the game system is running, do ticks.
 */
void GameSystem::init() {
	running = true;

	while (isRunning()) {
		doTick();
	}
}

/**
 * Unloads the current game (if present) and flags the game system
 * as no longer running.
 */
void GameSystem::shutdown() {
	unloadGame();
	running = false;
}

/**
 * Registers a game to the game system.
 * 
 * If a game with the same name already exists it will be replaced.
 * 
 * If the game system has already been initialised (ie. is running),
 * the game will not be registered.
 */
void GameSystem::registerGame(Game* game) {
	if (isRunning()) {
		return;
	}

	for (int i = 0; i < registeredGames.size(); i++) {
		if (registeredGames[i]->getName() == game->getName()) {
			delete registeredGames[i];
			registeredGames[i] = game;
			return;
		}
	}

	registeredGames.push_back(game);
}

/**
 * Gets all registered games.
 */
std::vector<Game*> GameSystem::getRegisteredGames() {
	return registeredGames;
}

/**
 * Gets the current loaded game, else NULL.
 */
Game* GameSystem::getLoadedGame() {
	return loadedGame;
}

/**
 * Attempts to load a game of specific name.
 * 
 * If the name is not associated with any registered game,
 * return false.
 * 
 * If there already exists a loaded game, unload it and proceed.
 */
bool GameSystem::loadGame(std::string gameName) {
	if (Utils::parseGame(gameName) == NULL) {
		return false;
	}
	if (getLoadedGame() != NULL) {
		unloadGame();
	}

	loadedGame = Utils::parseGame(gameName);
}

/**
 * If a loaded game exists, clean it,
 * then indicate there is no longer a loaded game
 * by setting the pointer to NULL.
 */
void GameSystem::unloadGame() {
	if (getLoadedGame() != NULL) {
		getLoadedGame()->cleanup();
		loadedGame = NULL;
	}
}

/**
 * Gets whether the game system is running.
 */
bool GameSystem::isRunning() {
	return running;
}

/**
 * Gets the command system.
 */
CommandSystem* GameSystem::getCommandSystem() {
	return commandSystem;
}

/**
 * Prints all registered games in a list, 
 * displaying their names and versions.
 * 
 * Here's an example of how it will look:
 * 
 * Game Selection:
 * 
 * 0. Tic Tac Toe | Version: 1.0.0
 * 1. Snakes & Ladders | Version: 1.0.0
 * 
 */
void GameSystem::printGameSelection() {
	std::cout << std::endl;
	log("Game Selection:", true);

	for (int i = 0; i < registeredGames.size(); i++) {
		log((std::to_string(i) + ". " + registeredGames[i]->getName() + " | Version: " + registeredGames[i]->getVersion()), true);
	}
	std::cout << std::endl;
}

/**
 * This function is one beefy boi, so buckle up.
 * 
 * Ticks are used by all GameSystem and Game objects.
 * 
 * 
 * > When are ticks called?
 * 
 * Ticks are called while the game or system is running. 
 * 
 * 
 * > How frequently are ticks called?
 * 
 * Ticks are called consecutively. A new tick is called once 
 * all code inside the previous tick has been executed.
 * For the GameSystem, this means waiting for a Game's tick
 * if one is loaded.
 * 
 * > What are ticks?
 * 
 * Ticks can be thought of as how this program keeps track
 * of which code needs to be executed before any other.
 * 
 * 
 * > What does this GameSystem tick do?
 * 
 * Read the comments inside the function block as it
 * will be easier for you to understand.
 */
void GameSystem::doTick() {
	// If a game is currently loaded,
	if (getLoadedGame()) {

		// If the game is running, call the game's next tick.
		if (getLoadedGame()->isRunning()) {
			getLoadedGame()->doTick();
		}

		// If the game has been ended, unload it.
		else if (getLoadedGame()->hasEnded()) {
			unloadGame();
		}

		// Else, since the game has not started, start it.
		else {
			getLoadedGame()->start();
		}
	}

	// Else, since no game is loaded, print and wait for input.
	else {
		// Prints the game selection
		printGameSelection();

		// Continue asking for input until a valid input is given.
		while (true) {
			log("Select a game: ", false);

			std::string input;
			std::cin >> input;

			// Check if the input is a command, if so, execute it.
			Command* cmd = commandSystem->parseCommand(input);
			if (cmd) {
				cmd->execute();
				log(("Executing command \"" + cmd->getArg() + "\"..."), true);
				break;
			}

			// If the input is an integer,
			else if (Utils::isInteger(input)) {
				int num = std::stoi(input);

				// If the number is in the range of game selection,
				// select the game and indicate it as loaded.
				if (num >= 0 && num < registeredGames.size()) {
					loadedGame = registeredGames[num];
					log(("Selected " + getLoadedGame()->getName() + "."), true);
					break;
				}
			}

			// Else there was no valid input, so tell the user they are an idiot.
			log("Invalid input.", true);
		}
	}
}

/**
 * Logs a message to the terminal.
 */
void GameSystem::log(std::string message, bool newLine) {
	std::cout << "[" << name << "] " << message;
	if (newLine) {
		std::cout << std::endl;
	}
}

/**
 * Cleans up dynamically allocated memory.
 */
GameSystem::~GameSystem() {
	delete loadedGame;
	delete commandSystem;

	for (auto p : registeredGames) {
		delete p;
	}
}