#ifndef TICTACTOEPLAYER_H
#define TICTACTOEPLAYER_H

#include "Player.h"

class TicTacToePlayer : public Player {

public:
	// Constructor
	TicTacToePlayer(std::string name, char marker);

	// Prints full display
	virtual void printDisplay();
	// Gets move
	virtual std::string getMove();
	// Gets marker
	char getMarker();

private:
	char marker;

};

#endif //TICTACTOEPLAYER_H