#ifndef GAME_H
#define GAME_H

#include <string>

#include "Board.h"
#include "Player.h"
#include "TurnTracker.h"

class Game {

public:
	// Constructor
	Game(std::string name, std::string version);

	// Gets the name
	std::string getName();
	// Gets the version
	std::string getVersion();
	// Gets all players
	std::vector<Player*> getPlayers();
	// Runs the game
	virtual void start() = 0;
	// Stops the game
	virtual void stop() = 0;
	// Cleans up the object
	virtual void cleanup() = 0;
	// Does a game tick
	virtual void doTick() = 0;
	// Logs a message
	void log(std::string message, bool newLine);
	// Gets whether the game is running
	bool isRunning();
	// Gets whether the game has ended
	bool hasEnded();
	// Gets the board
	Board* getBoard();
	// Sets the board
	void setBoard(Board* board);

	// Deconstructor
	~Game();

protected:
	std::string name;
	std::string version;
	bool running;
	bool ended;
	Board* gameboard;
	TurnTracker tracker;
	std::vector<Player*> players;

	// Handles how the game ends
	virtual void handleEnd() = 0;

};





#endif //GAME_H