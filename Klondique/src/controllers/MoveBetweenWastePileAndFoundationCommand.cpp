#include <MoveBetweenWastePileAndFoundationCommand.h>
#include "LimitedInDialog.h"

MoveBetweenWastePileAndFoundationCommand::~MoveBetweenWastePileAndFoundationCommand() {
}

MoveBetweenWastePileAndFoundationCommand::MoveBetweenWastePileAndFoundationCommand(shared_ptr<Game> game):
	UndoableCommand("MoveBetweenWastePileAndFoundation", game)
{

}

void
MoveBetweenWastePileAndFoundationCommand::execute() {
	game->moveBetweenWastePileAndFoundation();
}

bool
MoveBetweenWastePileAndFoundationCommand::isActive()
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
MoveBetweenWastePileAndFoundationCommand::undo()
{
	game->undo();
}


void
MoveBetweenWastePileAndFoundationCommand::redo() {
	game->redo();
}

/*UndoableCommand
MoveBetweenWastePileAndFoundation::clone() {
	MoveCommand moveCommand = new MoveCommand(game);
	moveCommand.origin = origin.clone();
	moveCommand.target = target.clone();
	return moveCommand;
}*/


string
MoveBetweenWastePileAndFoundationCommand::toString()
{
	return "MoveBetweenWastePileAndFoundation";
	//return "MoveCommand [origin=" + origin + ", target=" + target + "]";
}

