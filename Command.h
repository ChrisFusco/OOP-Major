#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {

public:
	// Constructor
	Command(std::string arg);

	// Gets the command arg
	std::string getArg();
	// Executes the command
	virtual void execute() = 0;


private:
	std::string arg;

};

#endif //COMMAND_H