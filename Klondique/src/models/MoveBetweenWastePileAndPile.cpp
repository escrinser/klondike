#include <MoveBetweenWastePileAndPile.h>

#include "LimitedInDialog.h"

MoveBetweenWastePileAndPile::~MoveBetweenWastePileAndPile() {
}

MoveBetweenWastePileAndPile::MoveBetweenWastePileAndPile(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	UndoableCommand("MoveBetweenWastePileAndPile", game, commandRegistry)
{

}

void
MoveBetweenWastePileAndPile::execute() {
	string titlePileDialog = "Pile Number?";
	game->moveBetweenWastePileAndPile(LimitedInDialog::getInstance()->read(titlePileDialog, MIN_NUMBER_OF_PILES, MAX_NUMBER_OF_PILES));
}

bool
MoveBetweenWastePileAndPile::isActive()
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
MoveBetweenWastePileAndPile::undo()
{
	game->undo();
}


void
MoveBetweenWastePileAndPile::redo() {
	game->redo();
}

/*UndoableCommand
MoveBetweenWastePileAndPile::clone() {
	MoveCommand moveCommand = new MoveCommand(game, commandRegistry);
	moveCommand.origin = origin.clone();
	moveCommand.target = target.clone();
	return moveCommand;
}*/


string
MoveBetweenWastePileAndPile::toString()
{
	return "MoveBetweenWastePileAndPile";
	//return "MoveCommand [origin=" + origin + ", target=" + target + "]";
}
