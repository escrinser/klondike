#include <LocalGameController.h>
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

void
LocalGameController::accept(LocalOperationControllerVisitor* operationControllerVisitor)
{
	operationControllerVisitor->visit(this);
}



