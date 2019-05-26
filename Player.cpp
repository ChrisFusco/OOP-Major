#include "Player.h"

/**
 * Initialises the state of this object.
 */
Player::Player(std::string name) {
	this->name = name;
}

/**
 * Gets the name.
 */
std::string Player::getName() {
	return name;
}

/**
 * Gets the display name.
 */
std::string Player::getDisplayName() {
	return name;
}

/**
 * Gets wins.
 */
int Player::getWins() {
	return wins;
}

/**
 * Gets draws.
 */
int Player::getDraws() {
	return draws;
}

/**
 * Gets losses.
 */
int Player::getLosses() {
	return losses;
}

/**
 * Gets winstreak.
 */
int Player::getWinstreak() {
	return winstreak;
}

/**
 * Adds win.
 */
void Player::addWin() {
	wins++;
}

/**
 * Adds draw.
 */
void Player::addDraw() {
	draws++;
}

/**
 * Adds loss.
 */
void Player::addLoss() {
	losses++;
}

/**
 * Adds winstreak.
 */
void Player::addWinstreak() {
	winstreak++;
}

/**
 * Resets winstreak.
 */
void Player::resetWinstreak() {
	winstreak = 0;
}