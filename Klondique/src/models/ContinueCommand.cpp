#include <ContinueCommand.h>

ContinueCommand::~ContinueCommand() {

}

ContinueCommand::ContinueCommand(shared_ptr<Game> game):
	Command("Continue", game)
{

}

void
ContinueCommand::execute()
{
	game->setState(State::IN_GAME);
}

bool
ContinueCommand::isActive()
{
	if (game->getState() == State::FINAL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

