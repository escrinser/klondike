#include "Logic.h"

#include <iostream>

#include "OperationController.h"
#include "LocalContinueController.h"
#include "LocalGameController.h"
#include "LocalStartController.h"

#include "../../models/Game.h"
#include "../../utils/LimitedInDialog.h"


using namespace std;

Logic::Logic() {
	game = shared_ptr<Game>(new Game());
	startController = shared_ptr<LocalStartController>(new LocalStartController(game));
    gameController = shared_ptr<LocalGameController>(new LocalGameController(game));
    continueController = shared_ptr<LocalContinueController>(new LocalContinueController(game));
}

Logic::~Logic() {
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

