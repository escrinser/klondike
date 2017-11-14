#include <LocalStartController.h>

#include "OperationControllerVisitor.h"

#include "../../models/Game.h"

LocalStartController::~LocalStartController() {
	// TODO Auto-generated destructor stub
}

void
LocalStartController::setStart(State theState)
{
	game->startPlayingBoard();
	game->setState(theState);
}

void
LocalStartController::accept(OperationControllerVisitor* operationControllerVisitor)
{
	operationControllerVisitor->visit(this);
}

