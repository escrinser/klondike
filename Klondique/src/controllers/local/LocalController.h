#ifndef LOCALCONTROLLER_H_
#define LOCALCONTROLLER_H_

#include <memory>

#include "../../models/State.h"
#include "../Controller.h"

class Game;

using namespace std;

class LocalController : public Controller{
public:
	LocalController(shared_ptr<Game> theGame);
	virtual ~LocalController();
	void setState(State state);
	void printBoard();

protected:
	void clear();

private:
	shared_ptr<Game> game;
};

#endif /* LOCALCONTROLLER_H_ */
