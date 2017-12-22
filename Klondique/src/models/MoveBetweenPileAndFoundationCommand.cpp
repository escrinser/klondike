#include <MoveBetweenPileAndFoundationCommand.h>
#include "LimitedInDialog.h"

MoveBetweenPileAndFoundationCommand::~MoveBetweenPileAndFoundationCommand() {
}

MoveBetweenPileAndFoundationCommand::MoveBetweenPileAndFoundationCommand(shared_ptr<Game> game):
	UndoableCommand("MoveBetweenPileAndFoundation", game)
{

}

void
MoveBetweenPileAndFoundationCommand::execute() {
	string titlePileDialog = "Pile Number?";
	game->moveBetweenPileAndFoundation(LimitedInDialog::getInstance()->read(titlePileDialog, MIN_NUMBER_OF_PILES, MAX_NUMBER_OF_PILES));
}

bool
MoveBetweenPileAndFoundationCommand::isActive()
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
MoveBetweenPileAndFoundationCommand::undo()
{
	game->undo();
}


void
MoveBetweenPileAndFoundationCommand::redo() {
	game->redo();
}

/*UndoableCommand
MoveBetweenPileAndFoundation::clone() {
	MoveCommand moveCommand = new MoveCommand(game);
	moveCommand.origin = origin.clone();
	moveCommand.target = target.clone();
	return moveCommand;
}*/


string
MoveBetweenPileAndFoundationCommand::toString()
{
	return "MoveBetweenPileAndFoundation";
	//return "MoveCommand [origin=" + origin + ", target=" + target + "]";
}

