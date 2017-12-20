#include <MoveBetweenWastePileAndFoundation.h>

#include "LimitedInDialog.h"

MoveBetweenWastePileAndFoundation::~MoveBetweenWastePileAndFoundation() {
}

MoveBetweenWastePileAndFoundation::MoveBetweenWastePileAndFoundation(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	UndoableCommand("MoveBetweenWastePileAndFoundation", game, commandRegistry)
{

}

void
MoveBetweenWastePileAndFoundation::execute() {
	game->moveBetweenWastePileAndFoundation();
}

bool
MoveBetweenWastePileAndFoundation::isActive()
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
MoveBetweenWastePileAndFoundation::undo()
{
	game->undo();
}


void
MoveBetweenWastePileAndFoundation::redo() {
	game->redo();
}

/*UndoableCommand
MoveBetweenWastePileAndFoundation::clone() {
	MoveCommand moveCommand = new MoveCommand(game, commandRegistry);
	moveCommand.origin = origin.clone();
	moveCommand.target = target.clone();
	return moveCommand;
}*/


string
MoveBetweenWastePileAndFoundation::toString()
{
	return "MoveBetweenWastePileAndFoundation";
	//return "MoveCommand [origin=" + origin + ", target=" + target + "]";
}

