#include <LocalGameController.h>

#include "OperationControllerVisitor.h"

#include "../../models/Game.h"


LocalGameController::~LocalGameController() {
	// TODO Auto-generated destructor stub
}

void
LocalGameController::showBoard()
{
	game->showBoard();
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
LocalGameController::setState(State state)
{

}

void
LocalGameController::printBoard()
{

}



