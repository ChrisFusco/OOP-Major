#ifndef COMMANDSYSTEM_H
#define COMMANDSYSTEM_H

#include <string>
#include <vector>

#include "Command.h"

class CommandSystem {

public:
	// Default constructor
	CommandSystem();
	// Constructor
	CommandSystem(char qualifier);

	// Attempts to parse the arg to a command
	Command* parseCommand(std::string arg);
	// Registers a command to the system
	void registerCommand(Command* command);
	// Gets the qualifier
	char getQualifier();

	// Destructor
	~CommandSystem();

private:
	char qualifier;
	std::vector<Command*> commands;

};

#endif //COMMANDSYSTEM_H