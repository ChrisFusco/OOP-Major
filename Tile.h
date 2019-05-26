#ifndef TILE_H
#define TILE_H

#include <string>

class Tile {

public:
	// Constructor
	Tile(std::string state);

	// Get the state of the tile
	std::string getState();
	// Set a new state of the tile
	void setState(std::string state);

private:
	std::string state;

};

#endif //TILE_H