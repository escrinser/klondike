/*
 * GameController.h
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include <memory>
#include "OperationController.h"

class Game;

using namespace std;

class GameController : public OperationController{
public:
	GameController(shared_ptr<Game> theGame): OperationController(theGame), game(theGame){};
	virtual ~GameController();
	void control();
	void accept(KlondiqueView* klondiqueView);
private:
	shared_ptr<Game> game;
};

#endif /* GAMECONTROLLER_H_ */
