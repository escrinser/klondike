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
class MoveController;

using namespace std;

class Logic {
public:
	Logic();
	virtual ~Logic();
	void play();

private:
	shared_ptr<Game> game;
	shared_ptr<StartController> startController;
	shared_ptr<MoveController> moveController;
};

#endif /* LOGIC_H_ */
