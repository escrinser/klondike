/*
 * MoveController.h
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#ifndef MOVECONTROLLER_H_
#define MOVECONTROLLER_H_

#include <memory>
#include "OperationController.h"

class Game;

using namespace std;

class MoveController : public OperationController{
public:
	MoveController(shared_ptr<Game> theGame): OperationController(theGame), game(theGame){};
	virtual ~MoveController();
	void control();
private:
	shared_ptr<Game> game;
};

#endif /* MOVECONTROLLER_H_ */
