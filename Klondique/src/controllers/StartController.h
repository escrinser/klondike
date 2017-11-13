/*
 * StartController.h
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#ifndef STARTCONTROLLER_H_
#define STARTCONTROLLER_H_

#include <memory>
#include "OperationController.h"

class Game;

using namespace std;

class StartController : public OperationController {
public:
	StartController(shared_ptr<Game> theGame): OperationController(theGame), game(theGame){};
	virtual ~StartController();
	void control();
	void accept(KlondiqueView* klondiqueView);
private:
	shared_ptr<Game> game;
};

#endif /* STARTCONTROLLER_H_ */
