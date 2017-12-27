#include <UndoCommand.h>

UndoCommand::~UndoCommand() {

}

UndoCommand::UndoCommand(shared_ptr<Game> game):
	Command("Undo", game)
{

}

void
UndoCommand::execute()
{
	game->undo();
}

bool
UndoCommand::isActive() {
	if (game->getState() == State::IN_GAME) //TODO: Add undo only if any movement
	{
		return true;
	}
	else
	{
		return false;
	}
}
