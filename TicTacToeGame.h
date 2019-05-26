#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include <string>

#include "Game.h"

class TicTacToeGame : public Game {

public:
	// Constructor
	TicTacToeGame(std::string name, std::string version);

	// Runs the game
	virtual void start();
	// Stops the game
	virtual void stop();
	// Cleans up the object
	virtual void cleanup();
	// Does a game tick
	virtual void doTick();

private:
	// Handles how the game ends
	virtual void handleEnd();

};


#endif //TICTACTOEGAME_H