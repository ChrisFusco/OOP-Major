#include <iostream>

#include "TicTacToePlayer.h"

/**
 * Initialises the state of this object.
 */
TicTacToePlayer::TicTacToePlayer(std::string name, char marker) : Player(name) {
	this->marker = marker;
}

/**
 * Prints the display.
 */
void TicTacToePlayer::printDisplay() {
	std::cout << "=========={}==========" << std::endl;;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Marker: " << getMarker() << std::endl;
    std::cout << "Type: Human" << std::endl;
    std::cout << "Wins: " << getWins() << std::endl;
    std::cout << "Draws: " << getDraws() << std::endl;
    std::cout << "Losses: " << getLosses() << std::endl;
    std::cout << "Winstreak: " << getWinstreak() << std::endl;
    std::cout << "=========={}==========" << std::endl;
}

/**
 * Gets the player's input.
 */
std::string TicTacToePlayer::getMove() {
	std::string input;
	std::cin >> input;

	return input;
}

/**
 * Gets the marker.
 */
char TicTacToePlayer::getMarker() {
	return marker;
}