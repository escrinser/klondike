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
class OperationController;
//class LocalOperationController;
class LocalStartController;
class LocalGameController;
class LocalContinueController;

using namespace std;

class Logic {
public:
	Logic();
	virtual ~Logic();
	shared_ptr<OperationController> getController();
	//shared_ptr<LocalOperationController> getController();

private:
	shared_ptr<Game> game;
	shared_ptr<LocalStartController> startController;
	shared_ptr<LocalGameController> gameController;
	shared_ptr<LocalContinueController> continueController;
};

#endif /* LOGIC_H_ */
