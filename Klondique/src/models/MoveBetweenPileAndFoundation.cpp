#include <MoveBetweenPileAndFoundation.h>

#include "LimitedInDialog.h"

MoveBetweenPileAndFoundation::~MoveBetweenPileAndFoundation() {
}

MoveBetweenPileAndFoundation::MoveBetweenPileAndFoundation(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	UndoableCommand("MoveBetweenPileAndFoundation", game, commandRegistry)
{

}

void
MoveBetweenPileAndFoundation::execute() {
	string titlePileDialog = "Pile Number?";
	game->moveBetweenPileAndFoundation(LimitedInDialog::getInstance()->read(titlePileDialog, MIN_NUMBER_OF_PILES, MAX_NUMBER_OF_PILES));
}

bool
MoveBetweenPileAndFoundation::isActive()
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
MoveBetweenPileAndFoundation::undo()
{
	game->undo();
}


void
MoveBetweenPileAndFoundation::redo() {
	game->redo();
}

/*UndoableCommand
MoveBetweenPileAndFoundation::clone() {
	MoveCommand moveCommand = new MoveCommand(game, commandRegistry);
	moveCommand.origin = origin.clone();
	moveCommand.target = target.clone();
	return moveCommand;
}*/


string
MoveBetweenPileAndFoundation::toString()
{
	return "MoveBetweenPileAndFoundation";
	//return "MoveCommand [origin=" + origin + ", target=" + target + "]";
}

