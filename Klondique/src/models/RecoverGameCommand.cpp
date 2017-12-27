#include <RecoverGameCommand.h>

RecoverGameCommand::~RecoverGameCommand() {

}

RecoverGameCommand::RecoverGameCommand(shared_ptr<Game> game):
	Command("Recover Game", game)
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
