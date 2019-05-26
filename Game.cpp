#include <iostream>

#include "Game.h"

/**
 * Initialises the state of this object.
 */
Game::Game(std::string name, std::string version) {
	this->name = name;
	this->version = version;
	running = false;
	ended = false;
	gameboard = NULL;
	tracker = TurnTracker();
}

/**
 * Gets the name.
 */
std::string Game::getName() {
	return name;
}

/**
 * Gets the version.
 */
std::string Game::getVersion() {
	return version;
}

/**
 * Gets all players.
 */
std::vector<Player*> Game::getPlayers() {
	return players;
}

/**
 * Gets whether the game is running.
 */
bool Game::isRunning() {
	return running;
}

/**
 * Gets the board.
 */
Board* Game::getBoard() {
	return gameboard;
}

/**
 * Sets the board.
 */
void Game::setBoard(Board* board) {
	this->gameboard = board;
}

/**
 * Gets whether the game has ended.
 */
bool Game::hasEnded() {
	return ended;
}

/**
 * Logs a message to the terminal.
 */
void Game::log(std::string message, bool newLine) {
	std::cout << "[" << name << "] " << message;
	if (newLine) {
		std::cout << std::endl;
	}
}

/**
 * Cleans up dynamically allocated memory.
 */
Game::~Game() {
	delete gameboard;

	for (auto p : players) {
		delete p;
	}
}