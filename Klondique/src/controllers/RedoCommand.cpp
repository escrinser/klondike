#include <RedoCommand.h>

RedoCommand::~RedoCommand() {

}

RedoCommand::RedoCommand(shared_ptr<Game> game):
	Command("Redo", game)
{

}

void
RedoCommand::execute() {
	game->redo();
}

bool
RedoCommand::isActive() {
	if (game->getState() == State::IN_GAME)
	{
		return true;
	}
	else
	{
		return false;
	}
}

