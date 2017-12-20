#include <MoveBetweenPiles.h>

#include "LimitedInDialog.h"

MoveBetweenPiles::~MoveBetweenPiles() {
}

MoveBetweenPiles::MoveBetweenPiles(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	UndoableCommand("MoveBetweenPiles", game, commandRegistry)
{

}

void
MoveBetweenPiles::execute() {

	string titleCardDialog = "Card Number?";
	string titlePileDialog = "Pile Number?";

	//int movement;

	int pileNumberOrigin;
	int pileNumberDestination;
	int pileNumberOriginNumber = 0;
	cout << "Move card/cards between Piles"<<endl;
	cout << "Origin Pile"<<endl;
	pileNumberOrigin = LimitedInDialog::getInstance()->read(titlePileDialog, MIN_NUMBER_OF_PILES, MAX_NUMBER_OF_PILES);

	cout << "\nIs the last card? (yes/no)";
	string lastCard;

	cin >> lastCard;
	if (lastCard == "no")
	{
	   cout << "\nPile Origin Card Number: ";
	   pileNumberOriginNumber = LimitedInDialog::getInstance()->read(titleCardDialog, MIN_NUMBER_OF_CARDS, MAX_NUMBER_OF_CARDS);;
	}
	else
	{
	   pileNumberOriginNumber = 0;
	}

	cout << "Destination Pile"<<endl;
	pileNumberDestination = LimitedInDialog::getInstance()->read(titlePileDialog, MIN_NUMBER_OF_PILES, MAX_NUMBER_OF_PILES);;
	if (pileNumberOriginNumber != 0)
	{
	   cout << "Pile Origin: " << pileNumberOrigin << " number: " << pileNumberOriginNumber <<" Pile Destination: " << pileNumberDestination  << endl;
	}
	else
	{
	   cout << "Pile Origin: " << pileNumberOrigin << " Pile Destination: " << pileNumberDestination  << endl;
	}

	if (pileNumberOrigin == pileNumberDestination)
	{
	   cout << "Impossible movement, the same pile. Pile Origin: " << pileNumberOrigin << " and Pile Destination: " << pileNumberDestination  << endl;
	}
	else
	{
		game->moveBetweenPiles(pileNumberOrigin, pileNumberDestination, pileNumberOriginNumber);
	}
}

bool
MoveBetweenPiles::isActive()
{
	if ((game->getState() == State::IN_GAME)
			&& !game->hasWon())
	{
		return true;
	}
	else
	{
		return false;
	}
}


void
MoveBetweenPiles::undo()
{
	game->undo();
}


void
MoveBetweenPiles::redo() {
	game->redo();
}

/*UndoableCommand
MoveBetweenPiles::clone() {
	MoveCommand moveCommand = new MoveCommand(game, commandRegistry);
	moveCommand.origin = origin.clone();
	moveCommand.target = target.clone();
	return moveCommand;
}*/


string
MoveBetweenPiles::toString()
{
	return "MoveBetweenPiles";
	//return "MoveCommand [origin=" + origin + ", target=" + target + "]";
}


