#include <string>

#include "TicTacToePlayer.h"
#include "TicTacToeGame.h"
#include "TicTacToeBoard.h"
#include "GameSystem.h"



class Utils {

public:
	// Gets whether the string is an integer.
	static bool isInteger(const std::string s);
	// Attempts to parse a game from a name
	static Game* parseGame(std::string gameName);
	// Attempts to get a winner from a game
	static Player* getWinner(TicTacToeGame* game);

private:
	Utils() { };

	// Gets whether a player occupies 3 tiles in a row in a board
	static bool hasTripleInARow(TicTacToePlayer* player, TicTacToeBoard* board);

};