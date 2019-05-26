#ifndef STOPCOMMAND_H
#define STOPCOMMAND_H

#include "Command.h"

class StopCommand : public Command {

public:
	// Constructor
	StopCommand(std::string arg);
	// Executes the command
	virtual void execute();

};

#endif //STOPCOMMAND_H