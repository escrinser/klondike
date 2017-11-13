/*
 * Logic.h
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#ifndef LOGIC_H_
#define LOGIC_H_

#include <iostream>
#include <memory>

class Game;
class StartController;
class GameController;
class ContinueController;
class OperationController;

using namespace std;

class Logic {
public:
	Logic();
	virtual ~Logic();
	shared_ptr<OperationController> getController();

private:
	shared_ptr<Game> game;
	shared_ptr<StartController> startController;
	shared_ptr<GameController> gameController;
	shared_ptr<ContinueController> continueController;
};

#endif /* LOGIC_H_ */
