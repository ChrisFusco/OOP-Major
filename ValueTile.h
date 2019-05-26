#ifndef VALUETILE_H
#define VALUETILE_H

#include "Tile.h"

class ValueTile : public Tile {

public:
	// Constructor
	ValueTile(std::string state, int value);

	// Gets the value
	int getValue();
	// Sets the value
	void setValue(int value);

private:
	int value;

};

#endif //VALUETILE_H