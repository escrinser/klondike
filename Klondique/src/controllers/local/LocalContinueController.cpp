#include "LocalContinueController.h"

#include "OperationControllerVisitor.h"

#include "../../models/Game.h"

LocalContinueController::~LocalContinueController() {
	// TODO Auto-generated destructor stub
}

void
LocalContinueController::setContinue(int theOption)
{
	switch (theOption)
	{
	   case 1:
		   game->clear();
		   game->showBoard();
		   game->setState(State::INITIAL);
		   break;

	   case 2:
		   game->setState(State::IN_GAME);
		   break;

	   case 3:
		   game->setState(State::EXIT);
		   break;

	   default:
		   break;
	}
}

void
LocalContinueController::accept(OperationControllerVisitor* operationControllerVisitor)
{
	operationControllerVisitor->visit(this);
}


