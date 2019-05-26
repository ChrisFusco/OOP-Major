#include <string>
#include <vector>

#include "TurnTracker.h"

/**
 * Initialises the state of this object.
 */
TurnTracker::TurnTracker() {
	nextTurn = -1;
}

/**
 * Initialises the state of this object.
 */
TurnTracker::TurnTracker(std::vector<Player*> players) {
	this->players = players;
	nextTurn = this->players.size() > 0 ? (rand() % this->players.size()) : 0;
}

/**
 * Gets the player for this turn.
 */
Player* TurnTracker::peek() {
	return players.empty() ? NULL : players[nextTurn];
}

/**
 * Gets the player for this turn, then progresses the tracker.
 */
Player* TurnTracker::poll() {
	progress();
	return players.empty() ? NULL : players[nextTurn];
}

/**
 * Adds 1 to the next turn index.
 *
 * If the index has reached it's max, set it to 0.
 */
void TurnTracker::progress() {
	if (nextTurn == (players.size()-1)) {
		nextTurn = 0;
	}
	else {
		nextTurn++;
	}
}