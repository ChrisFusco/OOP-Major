#include <iostream>
#include <string>

#include "GameSystem.h"
#include "TicTacToeGame.h"
#include "StopCommand.h"

using namespace std;

GameSystem gameSystem("Dollar-Store GameCube", "1.0.0");

int main() {

	Game** games = new Game*[1];
	Command** commands = new Command*[1];
	

	gameSystem.log(("Loading version " + gameSystem.getVersion() + "."), true);
	gameSystem.log("Entering preparation stage.", true);


	// Instantiates the Tic Tac Toe Game
	Game* tictactoe = new TicTacToeGame("Tic Tac Toe", "1.0.0");


	// Stores games in dynamic array
	*games = tictactoe;


	// Registers the Games to the GameSystem
	gameSystem.registerGame(tictactoe);
	gameSystem.log(("Registered Game: " + tictactoe->getName()), true);


	// Registers the stop command
	Command* stopCommand = new StopCommand("stop");
	gameSystem.getCommandSystem()->registerCommand(stopCommand);


	gameSystem.log("Finished preparation.", true);
	gameSystem.log("Initiating system.", true);


	// Initialises the GameSystem

	gameSystem.init();


	// When this code is reached, the GameSystem will no longer be running.
	// Shutdown tasks

	gameSystem.log("Shutting down.", true);

	delete[] games;
	delete[] commands;
}

