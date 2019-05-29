#include <iostream>

#include "HelpCommand.h"
#include "GameSystem.h"
#include "Game.h"

extern GameSystem gameSystem;

/**
 * Initialises the state of this object.
 */
HelpCommand::HelpCommand(std::string arg) : Command(arg) { }

/**
 * Executes the stop command.
 * 
 * If a game is running, stop it.
 * 
 * If not game is running and the game system is running, exit it.
 */
void HelpCommand::execute() {
	if (gameSystem.getLoadedGame()) {
		if (gameSystem.getLoadedGame()->isRunning()) {
			std::cout << std::endl;
			gameSystem.getLoadedGame()->log("* To make a move, enter a number shown on the board.", true);
			gameSystem.getLoadedGame()->log("* To exit the game at any time, enter \"!stop\"", true);
			gameSystem.getLoadedGame()->log("* Remember have fun.", true);
			std::cout << std::endl;
		}
	}
	else if (gameSystem.isRunning()) {
		std::cout << std::endl;
		gameSystem.log("* Pick a game from the list.", true);
		gameSystem.log("* To exit the system at any time, enter \"!stop\".", true);
		gameSystem.log("* Stats can be accessed after each game.", true);
		std::cout << std::endl;
	}
}