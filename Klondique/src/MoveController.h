/*
 * MoveController.h
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#ifndef MOVECONTROLLER_H_
#define MOVECONTROLLER_H_

#include <memory>

class Game;

using namespace std;

class MoveController {
public:
	MoveController(shared_ptr<Game>);
	virtual ~MoveController();
	void control();
private:
	shared_ptr<Game> game;
};

#endif /* MOVECONTROLLER_H_ */
