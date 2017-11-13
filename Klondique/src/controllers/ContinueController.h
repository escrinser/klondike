/*
 * ContinueController.h
 *
 *  Created on: 10 nov. 2017
 *      Author: eseogaz
 */

#ifndef CONTINUECONTROLLER_H_
#define CONTINUECONTROLLER_H_

#include <memory>
#include "OperationController.h"


class Game;

using namespace std;

class ContinueController : public OperationController{
public:
	ContinueController(shared_ptr<Game> theGame): OperationController(theGame), game(theGame){};
	virtual ~ContinueController();
	void control();
	void accept(KlondiqueView* klondiqueView);
private:
	shared_ptr<Game> game;
};

#endif /* CONTINUECONTROLLER_H_ */
