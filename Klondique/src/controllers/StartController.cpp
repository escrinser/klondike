#include "StartController.h"

#include "../models/Game.h"

StartController::~StartController() {
	// TODO Auto-generated destructor stub
}

void
StartController::setStart(State theState)
{
	game->startPlayingBoard();
	game->setState(theState);
}

void
StartController::accept(OperationControllerVisitor* operationControllerVisitor)
{
	operationControllerVisitor->visit(this);
}

