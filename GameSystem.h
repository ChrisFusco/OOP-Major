#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H

#include <string>
#include <vector>

#include "Game.h"
#include "CommandSystem.h"

class GameSystem {

public:
	// Constructor
	GameSystem(std::string name, std::string version);

	// Gets the name
	std::string getName();
	// Gets the version
	std::string getVersion();
	// Intialises the game system
	void init();
	// Shuts down the game system
	void shutdown();
	// Registers a Game
	void registerGame(Game* game);
	// Gets the registered games
	std::vector<Game*> getRegisteredGames();
	// Gets the current loaded game, else NULL
	Game* getLoadedGame();
	// Attempts to load a game by name
	bool loadGame(std::string gameName);
	// Unloads the current game, if present
	void unloadGame();
	// Gets whether the game system is running
	bool isRunning();
	// Gets the command system
	CommandSystem* getCommandSystem();
	// Prints the game selection
	void printGameSelection();
	// Logs a message
	void log(std::string message, bool newLine);

	// Deconsutrctor
	~GameSystem();

private:
	std::string name;
	std::string version;
	Game* loadedGame;
	std::vector<Game*> registeredGames;
	bool running;
	CommandSystem* commandSystem;

	// Does a system tick.
	void doTick();
};

// Global variable
extern GameSystem gameSystem;

#endif //GAMESYSTEM_H