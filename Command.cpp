#include "Command.h"

/**
 * Initialises the state of this object.
 */
Command::Command(std::string arg) {
	this->arg = arg;
}

/*
 * Gets the arg.
 */
std::string Command::getArg() {
	return arg;
}