#include <RedoCommand.h>

RedoCommand::~RedoCommand() {

}

RedoCommand::RedoCommand(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	Command("Redo", game, commandRegistry)
{

}

void
RedoCommand::execute() {
	game->redo();
}

bool
RedoCommand::isActive() {
	if (game->getState() == State::IN_GAME) //TODO: Add redo only if undo
	{
		return true;
	}
	else
	{
		return false;
	}
}

