#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {

public:
	// Constructor
	Player(std::string name);

	// Gets the name
	std::string getName();
	// Gets the display
	virtual std::string getDisplayName();
	// Gets wins
	int getWins();
	// Gets draws
	int getDraws();
	// Gets losses
	int getLosses();
	// Gets winstreak
	int getWinstreak();
	// Adds win
	void addWin();
	// Adds draw
	void addDraw();
	// Adds loss
	void addLoss();
	// Adds winstreak
	void addWinstreak();
	// Resets winstreak
	void resetWinstreak();
	// Prints full display
	virtual void printDisplay() = 0;
	// Gets move
	virtual std::string getMove() = 0;

private:
	std::string name;
	int wins;
	int draws;
	int losses;
	int winstreak;

};


#endif //PLAYER_H