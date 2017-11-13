#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <memory>
#include "../models/State.h"

class Game;

using namespace std;

class Controller {
public:
	Controller(shared_ptr<Game> theGame);
	virtual ~Controller();
	void setState(State state);
	void printBoard();
	bool hasWon();
protected:
	State getState();
	void clear();
	shared_ptr<Game> getGame();

private:
	shared_ptr<Game> game;
};

#endif /* CONTROLLER_H_ */
