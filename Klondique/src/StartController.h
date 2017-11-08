/*
 * StartController.h
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#ifndef STARTCONTROLLER_H_
#define STARTCONTROLLER_H_

#include <memory>

class Game;

using namespace std;

class StartController {
public:
	StartController(shared_ptr<Game>);
	virtual ~StartController();
	void control();
private:
	shared_ptr<Game> game;
};

#endif /* STARTCONTROLLER_H_ */
