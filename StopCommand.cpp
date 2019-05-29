#include "StopCommand.h"
#include "GameSystem.h"
#include "Game.h"

extern GameSystem gameSystem;

/**
 * Initialises the state of this object.
 */
StopCommand::StopCommand(std::string arg) : Command(arg) { }

/**
 * Executes the stop command.
 * 
 * If a game is running, stop it.
 * 
 * If not game is running and the game system is running, exit it.
 */
void StopCommand::execute() {
	if (gameSystem.getLoadedGame()) {
		if (gameSystem.getLoadedGame()->isRunning()) {
			gameSystem.getLoadedGame()->cleanup();
			gameSystem.getLoadedGame()->stop();
		}
	}
	else if (gameSystem.isRunning()) {
		gameSystem.shutdown();
	}
}