#include <iostream> 

#include "TicTacToeGame.h"
#include "TicTacToePlayer.h"
#include "TicTacToePlayerAI.h"
#include "TicTacToeBoard.h"
#include "Utils.h"

extern GameSystem gameSystem;

/**
 * Initialises the state of this object.
 */
TicTacToeGame::TicTacToeGame(std::string name, std::string version) : Game(name, version) { }

/**
 * Prepares and starts the game.
 * 
 * Read commands in function block for more details.
 */
void TicTacToeGame::start() {

	// Since there are only 2 modes, we can use a simple boolean switch
	// Singleplayer = false, Multiplayer = true.
	bool mode = false;

	while (true) {
		log("[S]ingleplayer/[M]ultiplayer: ", false);
		std::string input;
		std::cin >> input;

		if (input[0] == 'S' || input[0] == 's') {
			mode = false;
			break;
		}
		else if (input[0] == 'M' || input[0] == 'm') {
			mode = true;
			break;
		}
	}

	// Singleplayer
	if (!mode) {
		// Creates and registers the AI Player
		TicTacToePlayerAI* ai = new TicTacToePlayerAI("TicTacToe AI", 'X');
		players.push_back(ai);
	}
	else {
		// Creates and registers the Player 2
		log("Enter username (Player 2): ", false);
		std::string name;
		std::cin >> name;
		TicTacToePlayer* player = new TicTacToePlayer(name, 'X');
		players.push_back(player);
	}

	// Creates the Player
	log(("Enter username (Player): "), false);
	std::string name;
	std::cin >> name;
	TicTacToePlayer* player = new TicTacToePlayer(name, 'O');

	// Registers the player
	players.push_back(player);

	// Creates a new tracker
	tracker = TurnTracker(players);

	// Creates the gameboard
	gameboard = new TicTacToeBoard();

	// Flags the game as running
	running = true;
}

/**
 * Flags the game as ended and no longer running.
 */
void TicTacToeGame::stop() {
	ended = true;
	running = false;
}

/**
 * Cleans up the object awaiting next play.
 * 
 * > Cleans dynamically allocated memory.
 * > Resets state.
 */
void TicTacToeGame::cleanup() {
	for (auto p : players) {
		delete p;
	}
	players.clear();

	gameboard = new TicTacToeBoard();
	ended = false;
	running = false;
	tracker = TurnTracker();
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
 * > What does this TicTacToe Game tick do?
 * 
 * Read the comments inside the function block as it
 * will be easier for you to understand.
 */
void TicTacToeGame::doTick() {

	// Checks to see if the board needs to be printed
	bool printBoard = true;

	// This will always work since the board is set in constructor and is private
	TicTacToeBoard* board = dynamic_cast<TicTacToeBoard*>(getBoard());

	// Prints the board only when it's a non-ai player's turn
	if (TicTacToePlayer* player = dynamic_cast<TicTacToePlayer*>(tracker.peek())) {
		if (!dynamic_cast<TicTacToePlayerAI*>(tracker.peek())) {
			// Prints the board
			if (printBoard) {
				board->print();
				printBoard = false;
			}
		}
	}

	// The game has no more turns left
	if (board->isFull()) {
		handleEnd();
	}

	// The game has turns left but there is a winner
	else if (Utils::getWinner(this)) {
		handleEnd();
	}

	// Else, do move
	else {

		while (true) {
			std::string input = "";

			if (TicTacToePlayer* player = dynamic_cast<TicTacToePlayer*>(tracker.peek())) {
				if (!dynamic_cast<TicTacToePlayerAI*>(tracker.peek())) {
					// Tells player to make their move
					log(("Select your move, " + player->getName() + " (" + player->getMarker() + "): "), false);
				}

				// Gets the move
				input = tracker.peek()->getMove();
			}

			if (input[0] == gameSystem.getCommandSystem()->getQualifier()) {
				// Check if the input is a command, if so, execute it.
				Command* cmd = gameSystem.getCommandSystem()->parseCommand(input);

				if (cmd) {
					log(("Executing command \"" + cmd->getArg() + "\"..."), true);
					cmd->execute();
					break;
				}
				else {
					log("Invalid command.", true);
					continue;
				}
			}

			// Checks if the algorithm has errored
			else if (input == "Error") {
				log("The algorithm has errored. Stopping game.", true);
				stop();
				break;
			}

			// If the input is an integer,
			else if (Utils::isInteger(input)) {
				int num = std::stoi(input);

				// If the number is in the range of possible moves
				if (num >= 0 && num <= 8) {
					
					// If the state is an integer, that means the tile hasn't been chosen as a move yet
					if (Utils::isInteger(gameboard->getTiles()[num]->getState())) {
						TicTacToePlayer* player = dynamic_cast<TicTacToePlayer*>(tracker.peek());

						// Handles the move
						gameboard->getTiles()[num]->setState(std::string(1, player->getMarker()));
						tracker.poll();
						printBoard = true;
						break;
					}
					else {
						log("That move has already been made.", true);
						continue;
					}
				}
			}

			// Else there was no valid input, so tell the user they are an idiot.
			log("Invalid input.", true);
		}
	}
}

/**
 * Handles a match ending.
 * 
 * Applies respected stats to winner and loser(s).
 */
void TicTacToeGame::handleEnd() {
	Player* winner = Utils::getWinner(this);

	// There is a winner
	if (winner) {
		log(("The winner is: " + winner->getName()), true);

		// Handles winner stats
		winner->addWin();
		winner->addWinstreak();

		// Handles loser stats
		for (Player* loser : players) {
			if (loser->getName() != winner->getName()) {
				loser->addLoss();
				loser->resetWinstreak();
			}
		}
	}
	// Else no winner
	else {
		log("The game ended in a draw!", true);

		for (Player* player : players) {
			player->addDraw();
			player->resetWinstreak();
		}
	}

	while (true) {
		log("Print stats? [Y/N]: ", false);
		std::string displayStats;
		std::cin >> displayStats;

		if (displayStats[0] == 'Y' || displayStats[0] == 'y') {
			// Prints stats
			for (Player* player : players) {
				std::cout << std::endl;
				player->printDisplay();
			}
			std::cout << std::endl;
			break;
		}
		else if (displayStats[0] == 'N' || displayStats[0] == 'n') {
			break;
		}
	}

	while (true) {
		log("Would you like a rematch? [Y/N]: ", false);
		std::string input;
		std::cin >> input;

		if (input[0] == 'Y' || input[0] == 'y') {
			gameboard->reset();
			break;
		}
		else if (input[0] == 'N' || input[0] == 'n') {
			cleanup();
			stop();
			break;
		}
	}
}