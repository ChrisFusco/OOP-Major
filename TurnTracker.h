#ifndef TURNTRACKER_H
#define TURNTRACKER_H

#include <string>
#include <vector>

#include "Player.h"

//tracks which players turn is currently active
class TurnTracker {
public:
	// Default constructor
	TurnTracker();
	// Constructor with vector parameter
	TurnTracker(std::vector<Player*> players);
	
	// Gets the player for next move
	Player* peek();
	// Gets the player for next move and progresses the tracker
	Player* poll();

private:
	// The pointers are taken care of in the Game deconstructor
	std::vector<Player*> players;
	int nextTurn;

	// Progresses the tracker
	void progress();
};

#endif //TURNTRACKER_H