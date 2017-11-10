/*
 * Logic.cpp
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#include "Logic.h"

#include <iostream>

#include "../models/Game.h"
#include "OperationController.h"
#include "StartController.h"
#include "ContinueController.h"
#include "GameController.h"
#include "../utils/LimitedInDialog.h"


using namespace std;

Logic::Logic() {
	game = shared_ptr<Game>(new Game());
	startController = shared_ptr<StartController>(new StartController(game));
    gameController = shared_ptr<GameController>(new GameController(game));
    continueController = shared_ptr<ContinueController>(new ContinueController(game));
}

Logic::~Logic() {
	// TODO Auto-generated destructor stub
}

void
Logic::play()
{
	shared_ptr<OperationController> controller;
	do {
		controller = getController();
		if (controller != nullptr)
		{
			controller->control();
		}
	} while (controller != nullptr);
}

shared_ptr<OperationController>
Logic::getController()
{
		switch (game->getState())
		{
			case INITIAL:
				return startController;
			case IN_GAME:
				return gameController;
			case FINAL:
				return continueController;
			case EXIT:
			default:
				return nullptr;
		}
}

