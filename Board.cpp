#include "Board.h"

/**
 * Initialises the state of this object.
 */
Board::Board() { }

/**
 * Gets all tiles.
 */
std::vector<Tile*> Board::getTiles() {
	return tiles;
}

/**
 * Cleans up dynamically allocated memory.
 */
Board::~Board() {
	for (auto p : tiles) {
		delete p;
	}
}