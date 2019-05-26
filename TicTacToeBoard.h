#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H

#include "Board.h"

class TicTacToeBoard : public Board {

public:
	// Default constructor
	TicTacToeBoard();

	// Resets the board
	virtual void reset();
	// Prints the board
	virtual void print();
	// Gets whether the board is empty
	bool isEmpty();
	// Gets whether the board is full
	bool isFull();

	// Deconstructor
	~TicTacToeBoard();

};


#endif //TICTACTOEBOARD_H