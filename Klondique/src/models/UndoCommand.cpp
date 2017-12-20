#include <UndoCommand.h>

UndoCommand::~UndoCommand() {

}

UndoCommand::UndoCommand(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	Command("Undo", game, commandRegistry)
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
