#ifndef LOCALCONTROLLER_H_
#define LOCALCONTROLLER_H_

#include <memory>

#include "../../models/State.h"

class Game;

using namespace std;

class LocalController {
public:
	LocalController(shared_ptr<Game> theGame);
	virtual ~LocalController();
	void setState(State state);
	void printBoard();

protected:
	State getState();
	void clear();
	shared_ptr<Game> getGame();

private:
	shared_ptr<Game> game;
};

#endif /* LOCALCONTROLLER_H_ */
