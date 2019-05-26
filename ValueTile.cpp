#include "ValueTile.h"

/**
 * Initialises the state of this object.
 */
ValueTile::ValueTile(std::string state, int value) : Tile(state) {
	this->value = value;
}

/**
 * Gets the value.
 */
int ValueTile::getValue() {
	return value;
}

/**
 * Sets the value.
 */
void ValueTile::setValue(int value) {
	this->value = value;
}