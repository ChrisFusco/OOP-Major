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
 * > How does it work?
 * 
 * Returns a random empty tile.
 */
std::string TicTacToePlayerAI::getMove() {

    std::vector<Tile*> emptyTiles;

    for (int i = 0; i < 9; i++) {
        Tile* tile = gameSystem.getLoadedGame()->getBoard()->getTiles()[i];

        // If true the tile is empty
        if (Utils::isInteger(tile->getState())) {

            emptyTiles.push_back(tile);
        }
    }

    if (!emptyTiles.empty()) {
        // Returns the empty tile at a random index
        return (emptyTiles[(rand() % emptyTiles.size())]->getState());
    }

    // Returns error
    return "Error";
}