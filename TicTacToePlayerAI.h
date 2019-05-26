#ifndef TICTACTOEPLAYERAI_H
#define TICTACTOEPLAYERAI_H

#include "TicTacToePlayer.h"

class TicTacToePlayerAI : public TicTacToePlayer {

public:
	// Constructor
	TicTacToePlayerAI(std::string name, char marker);

	// Prints full display
	virtual void printDisplay();
	// Gets move
	virtual std::string getMove();
};

#endif //TICTACTOEPLAYERAI_H