#include <RecoverGameCommand.h>

RecoverGameCommand::~RecoverGameCommand() {

}

RecoverGameCommand::RecoverGameCommand(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	Command("Recover Game", game, commandRegistry)
{

}

void
RecoverGameCommand::execute()
{
	game->recoverGame();
}

bool
RecoverGameCommand::isActive() {
	if (game->getState() == State::INITIAL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
