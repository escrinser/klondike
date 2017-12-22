#include <ContinueMenuCommand.h>

ContinueMenuCommand::~ContinueMenuCommand() {

}

ContinueMenuCommand::ContinueMenuCommand(shared_ptr<Game> game):
	Command("Continue Menu", game)
{

}

void
ContinueMenuCommand::execute()
{
	game->setState(State::FINAL);
}

bool
ContinueMenuCommand::isActive() {
	if (game->getState() == State::IN_GAME)
	{
		return true;
	}
	else
	{
		return false;
	}
}

