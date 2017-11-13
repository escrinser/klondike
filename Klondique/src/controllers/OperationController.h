/*
 * OperationController.h
 *
 *  Created on: 9 nov. 2017
 *      Author: eseogaz
 */

#ifndef OPERATIONCONTROLLER_H_
#define OPERATIONCONTROLLER_H_

#include <memory>

#include "Controller.h"

class Game;
class KlondiqueView;

using namespace std;

class OperationController : public Controller {
public:
	OperationController(shared_ptr<Game> theGame): Controller(theGame), game(theGame){};
	virtual ~OperationController();
	virtual void control() = 0;
	virtual void accept(KlondiqueView* klondiqueView) = 0;
private:
	shared_ptr<Game> game;
};

#endif /* OPERATIONCONTROLLER_H_ */
