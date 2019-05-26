#include <algorithm>
#include <iostream>

#include "CommandSystem.h"

CommandSystem::CommandSystem() {
	this->qualifier = '!';
}

/**
 * Initialises the state of this object.
 */
CommandSystem::CommandSystem(char qualifier) {
	this->qualifier = qualifier;
}

/**
 * Gets the qualifier.
 */
char CommandSystem::getQualifier() {
	return qualifier;
}

/**
 * If a command's arg equals the function arg, it will retrieve that command,
 * else null.
 */
Command* CommandSystem::parseCommand(std::string arg) {
	arg.erase(std::remove(arg.begin(), arg.end(), qualifier), arg.end());

	for (Command* cmd : commands) {
		if (cmd->getArg() == arg) {
			return cmd;
		}
	}

	return NULL;
}

/**
 * Registers a command to the game system.
 * 
 * If a command with the same arg already exists it will be replaced.
 */
void CommandSystem::registerCommand(Command* command) {
	for (int i = 0; i < commands.size(); i++) {
		if (commands[i]->getArg() == command->getArg()) {
			delete commands[i];
			commands.erase(commands.begin() + i);
		}
	}

	commands.push_back(command);
}

/**
 * Cleans up dynamically allocated memory.
 */
CommandSystem::~CommandSystem() {
	for (auto p : commands) {
		delete p;
	}
}