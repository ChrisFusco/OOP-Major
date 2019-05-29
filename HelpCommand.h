#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H

#include "Command.h"

class HelpCommand : public Command {

public:
	// Constructor
	HelpCommand(std::string arg);
	// Executes the command
	virtual void execute();

};

#endif //HELPCOMMAND_H