#include <MoveBetweenWastePileAndFoundationCommand.h>
#include "LimitedInDialog.h"

MoveBetweenWastePileAndFoundationCommand::~MoveBetweenWastePileAndFoundationCommand() {
}

MoveBetweenWastePileAndFoundationCommand::MoveBetweenWastePileAndFoundationCommand(shared_ptr<Game> game):
	UndoRedoAbleCommand("MoveBetweenWastePileAndFoundation", game)
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

string
MoveBetweenWastePileAndFoundationCommand::toString()
{
	return "MoveBetweenWastePileAndFoundation";
}

