#include "Tile.h"

/**
 * Initialises the state of this object.
 */
Tile::Tile(std::string state) {
	this->state = state;
}

/**
 * Gets the state.
 */
std::string Tile::getState() {
	return state;
}

/**
 * Sets the state.
 */
void Tile::setState(std::string state) {
	this->state = state;
}