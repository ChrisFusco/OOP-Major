#include <iostream>

#include "TicTacToeBoard.h"
#include "Tile.h"
#include "Utils.h"

/**
 * Initialises the state of this object.
 */
TicTacToeBoard::TicTacToeBoard() {
	// Sets up the starting state of the board
	for (int i = 0; i < 9; i++) {
		tiles.push_back(new Tile(std::to_string(i)));
	}
}

/**
 * Resets the board to it's starting state.
 */ 
void TicTacToeBoard::reset() {
	// Resets tiles to default numbered state
	for (int i = 0; i < 9; i++) {
		tiles[i]->setState(std::to_string(i));
	}
}

/**
 * Prints the board to the terminal.
 */
void TicTacToeBoard::print() {
	std::cout << " ___ ___ ___" << std::endl;
	std::cout << "|";
	for (int i = 0; i < 9; i++) {
		if(i < 3){
			std::cout <<" "<< tiles[i]->getState() << " |";
		}
		if(i == 3){
			std::cout << std::endl;
			std::cout << "|___|___|___|" << std::endl;
			std::cout <<"| "<< tiles[i]->getState() << " |";
		}
		if(i == 4 || i == 5){
			std::cout <<" "<< tiles[i]->getState() << " |";
		}
		if(i == 6){
			std::cout << std::endl;
			std::cout << "|___|___|___|" << std::endl;
			std::cout <<"| "<< tiles[i]->getState() << " |";
		}
		if(i == 7 || i == 8){
			std::cout <<" "<< tiles[i]->getState() << " |";
		}
	}
	std::cout << std::endl;
	std::cout << "|___|___|___|" << std::endl;
	std::cout << std::endl;
}

/**
 * Gets whether the board is empty.
 */
bool TicTacToeBoard::isEmpty() {
	for (int i = 0; i < 9; i++) {

		// If the state is a number it's a free slot
		if (!Utils::isInteger(tiles[i]->getState())) {
			return false;
		}
	}

	return true;
}

/**
 * Gets whether the board is full.
 */
bool TicTacToeBoard::isFull() {
	for (int i = 0; i < 9; i++) {
		// If the state is a number it's a free slot
		if (Utils::isInteger(tiles[i]->getState())) {
			return false;
		}
	}

	return true;
}

/**
 * Cleans up dynamically allocated memory.
 */
TicTacToeBoard::~TicTacToeBoard() {
	for (auto p : tiles) {
		delete p;
	}
}