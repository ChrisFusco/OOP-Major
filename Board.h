#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "Tile.h"

class Board {

public:
	// Default constructor
	Board();

	// Gets all tiles
	std::vector<Tile*> getTiles();
	// Resets the board
	virtual void reset() = 0;
	// Prints the board
	virtual void print() = 0;

	// Deconstructor
	~Board();

protected:
	std::vector<Tile*> tiles;

};


#endif //BOARD_H