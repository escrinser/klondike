/*
 * Controller.h
 *
 *  Created on: 10 nov. 2017
 *      Author: eseogaz
 */

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

protected:
	State getState(); //TODO: Is it necessary this Controller ?
	void setState(State state);
	void clear();
	bool hasWon();
	shared_ptr<Game> getGame();

private:
	shared_ptr<Game> game;
};

#endif /* CONTROLLER_H_ */
