#include <iostream>

#include "TicTacToePlayerAI.h"
#include "Game.h"
#include "GameSystem.h"
#include "Utils.h"

extern GameSystem gameSystem;

/**
 * Initialises the state of this object.
 */
TicTacToePlayerAI::TicTacToePlayerAI(std::string name, char marker) : TicTacToePlayer(name, marker) { }

/**
 * Prints the display.
 */
void TicTacToePlayerAI::printDisplay() {
	std::cout << "=========={}==========" << std::endl;;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Marker: " << getMarker() << std::endl;
    std::cout << "Type: AI" << std::endl;
    std::cout << "Wins: " << getWins() << std::endl;
    std::cout << "Draws: " << getDraws() << std::endl;
    std::cout << "Losses: " << getLosses() << std::endl;
    std::cout << "Winstreak: " << getWinstreak() << std::endl;
    std::cout << "=========={}==========" << std::endl;
}

/**
 * Tic Tac Toe Algorithm.
 * 
 * A game should always be loaded when this function is called.
 * 
 * TODO
 */
std::string TicTacToePlayerAI::getMove() {

    // Holds the ratings for the tiles
    int* ratings = new int[9]{NULL};


    for (int i = 0; i < 9; i++) {
        Tile* tile = gameSystem.getLoadedGame()->getBoard()->getTiles()[i];

        // If true the tile is a possible move
        if (Utils::isInteger(tile->getState())) {

            // If the number is 1-3,


            return tile->getState();
        }

    }

    return "Error";
}