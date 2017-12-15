#include "LocalGameController.h"

#include "OperationControllerVisitor.h"

#include "../../models/Game.h"


LocalGameController::~LocalGameController() {
}

void
LocalGameController::deal()
{
	game->deal();
}

void
LocalGameController::moveBetweenPiles(int thePileOriginNumber,
	     	 	 	  int thePileDestinationNumber,
					  int theCardOriginNumber)
{
	game->moveBetweenPiles(thePileOriginNumber, thePileDestinationNumber, theCardOriginNumber);
}

void
LocalGameController::moveBetweenWastePileAndPile(int thePileDestinationNumber)
{
	game->moveBetweenWastePileAndPile(thePileDestinationNumber);
}

void
LocalGameController::moveBetweenWastePileAndFoundation()
{
	game->moveBetweenWastePileAndFoundation();
}

void
LocalGameController::moveBetweenPileAndFoundation(int thePileOriginNumber)
{
	game->moveBetweenPileAndFoundation(thePileOriginNumber);
}

bool
LocalGameController::hasWon()
{
	return game->hasWon();
}

void
LocalGameController::accept(OperationControllerVisitor* operationControllerVisitor)
{
	operationControllerVisitor->visit(this);
}

void
LocalGameController::setState(State state) {
	game->setState(state);
}

void
LocalGameController::printBoard()
{
	game->showBoard();
}

void
LocalGameController::undo()
{
	cout << "LocalGameController::undo()"<<endl;
	game->undo();
}

void
LocalGameController::redo()
{
	cout << "LocalGameController::redo()"<<endl;
	game->redo();
}


