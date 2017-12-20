#include <ContinueCommand.h>

ContinueCommand::~ContinueCommand() {

}

ContinueCommand::ContinueCommand(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	Command("Continue", game, commandRegistry)
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

