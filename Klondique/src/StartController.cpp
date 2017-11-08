/*
 * StartController.cpp
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#include "StartController.h"

#include "Game.h"

StartController::StartController(shared_ptr<Game> theGame) {
	game = theGame;
}

StartController::~StartController() {
	// TODO Auto-generated destructor stub
}

void
StartController::control()
{
	//assert this.getState() == State.INITIAL;
	//int users = new LimitedIntDialog("Cuántos usuarios?", 0, this.getGame().getNumPlayers()).read();
	//colocateControllerBuilder.build(users);
	//this.write();
	game->setState(State::IN_GAME);
}

