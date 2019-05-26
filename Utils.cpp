#include <iostream>
#include <string>

#include "Utils.h"
#include "Board.h"
#include "TicTacToePlayer.h"
#include "TicTacToePlayerAI.h"
#include "TicTacToeGame.h"
#include "TicTacToeBoard.h"
#include "GameSystem.h"

extern GameSystem gameSystem;

/**
 * Code used from:
 * https://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int
 * 
 * An in-depth description of what this function does is available at the link.
 * 
 * It has been slightly modified to handle memory cleanup.
 */
bool Utils::isInteger(const std::string s) {
	return s.find_first_not_of( "0123456789" ) == std::string::npos;
}

/**
 * If there exists a registered game with the same name it will be returned,
 * else NULL.
 */
Game* Utils::parseGame(std::string gameName) {
	for (int i = 0; i < gameSystem.getRegisteredGames().size(); i++) {
		if (gameSystem.getRegisteredGames()[i]->getName() == gameName) {
			return gameSystem.getRegisteredGames()[i];
		}
	}

	return NULL;
}

/**
 * Iterates through the game's players to check if any of them have won, else NULL.
 */
Player* Utils::getWinner(TicTacToeGame* game) {
	for (Player* p : game->getPlayers()) {

		// Attempts to type cast player
		if (TicTacToePlayer* player = dynamic_cast<TicTacToePlayer*>(p)) {

			// Attempts to type cast board
			if (TicTacToeBoard* board = dynamic_cast<TicTacToeBoard*>(game->getBoard())) {

        		if (hasTripleInARow(player, board)) {
        			return p;
        		}
    		}
		}
	}

	return NULL;
}

/**
 * > How this algorithm works:
 * 
 * This algorithm uses the middle tile first to check if it's involved in
 * a complete triple.
 * 
 * If no triple is found, check the sides using 2 opposite corners (top left, bottom right)
 * 
 * If no triple is found, return false;
 */
bool Utils::hasTripleInARow(TicTacToePlayer* player, TicTacToeBoard* board) {

	// Check middle first

	// If middle tile is occupied by the player
	if (board->getTiles()[4]->getState() == std::string(1, player->getMarker())) {

		// Check top left first
		// If top left is occupied by the player, check opposite (bottom right)
		if (board->getTiles()[0]->getState() == std::string(1, player->getMarker())) {

			// If bottom right is also occupied, then found a triple
			if (board->getTiles()[8]->getState() == std::string(1, player->getMarker())) {
				return true;
			}
		}

		// Check top middle next
		// If top middle is occupied by the player, check opposite (bottom middle)
		else if (board->getTiles()[1]->getState() == std::string(1, player->getMarker())) {

			// If bottom middle is also occupied, then found a triple
			if (board->getTiles()[7]->getState() == std::string(1, player->getMarker())) {
				return true;
			}
		}

		// Check top right next
		// If top right is occupied by the player, check opposite (bottom left)
		else if (board->getTiles()[2]->getState() == std::string(1, player->getMarker())) {

			// If bottom left is also occupied, then found a triple
			if (board->getTiles()[6]->getState() == std::string(1, player->getMarker())) {
				return true;
			}
		}

		// Check middle right next
		// If middle right is occupied by the player, check opposite (middle left)
		else if (board->getTiles()[5]->getState() == std::string(1, player->getMarker())) {

			// If middle left is also occupied, then found a triple
			if (board->getTiles()[3]->getState() == std::string(1, player->getMarker())) {
				return true;
			}
		}
	}

	// Check sides next (top left and bottom right)

	// If first tile is occupied by the player
	else if (board->getTiles()[0]->getState() == std::string(1, player->getMarker())) {

		// Check 1 downward
		// If the tile is occupied by the player
		if (board->getTiles()[3]->getState() == std::string(1, player->getMarker())) {

			// Check 2 downward
			// If the tile is occupied by the player, they have 3 in a row
			if (board->getTiles()[6]->getState() == std::string(1, player->getMarker())) {
				return true;
			}
		}

		// Check 1 to the right
		// If the tile is occupied by the player
		if (board->getTiles()[1]->getState() == std::string(1, player->getMarker())) {

			// Check 2 to the right
			// If the tile is occupied by the player, they have 3 in a row
			if (board->getTiles()[2]->getState() == std::string(1, player->getMarker())) {
				return true;
			}
		}
	}

	// If last tile is occupied by the player
	else if (board->getTiles()[8]->getState() == std::string(1, player->getMarker())) {

		// Check 1 upward
		// If the tile is occupied by the player
		if (board->getTiles()[5]->getState() == std::string(1, player->getMarker())) {

			// Check 2 upward
			// If the tile is occupied by the player, they have 3 in a row
			if (board->getTiles()[2]->getState() == std::string(1, player->getMarker())) {
				return true;
			}
		}

		// Check 1 to the left
		// If the tile is occupied by the player
		if (board->getTiles()[7]->getState() == std::string(1, player->getMarker())) {

			// Check 2 to the left
			// If the tile is occupied by the player, they have 3 in a row
			if (board->getTiles()[6]->getState() == std::string(1, player->getMarker())) {
				return true;
			}
		}
	}

	return false;
}