#include "LocalStartController.h"

#include "OperationControllerVisitor.h"

#include "../../models/Game.h"

LocalStartController::~LocalStartController() {
}

void
LocalStartController::setStart()
{
	game->startPlayingBoard();
}

void
LocalStartController::setState(State state)
{
	game->setState(state);
}

void
LocalStartController::printBoard()
{
	game->showBoard();
}


void
LocalStartController::accept(OperationControllerVisitor* operationControllerVisitor)
{
	operationControllerVisitor->visit(this);
}

