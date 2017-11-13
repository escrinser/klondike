#include "GameController.h"

#include "../models/Game.h"


GameController::~GameController() {
	// TODO Auto-generated destructor stub
}

void
GameController::showBoard()
{
	game->showBoard();
}

void
GameController::deal()
{
	game->deal();
}

void
GameController::moveBetweenPiles(int thePileOriginNumber,
	     	 	 	  int thePileDestinationNumber,
					  int theCardOriginNumber)
{
	game->moveBetweenPiles(thePileOriginNumber, thePileDestinationNumber, theCardOriginNumber);
}

void
GameController::moveBetweenWastePileAndPile(int thePileDestinationNumber)
{
	game->moveBetweenWastePileAndPile(thePileDestinationNumber);
}

void
GameController::moveBetweenWastePileAndFoundation()
{
	game->moveBetweenWastePileAndFoundation();
}

void
GameController::moveBetweenPileAndFoundation(int thePileOriginNumber)
{
	game->moveBetweenPileAndFoundation(thePileOriginNumber);
}

void
GameController::accept(OperationControllerVisitor* operationControllerVisitor)
{
	operationControllerVisitor->visit(this);
}



