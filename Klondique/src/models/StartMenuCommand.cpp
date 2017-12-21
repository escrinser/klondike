#include <StartMenuCommand.h>

StartMenuCommand::~StartMenuCommand() {

}

StartMenuCommand::StartMenuCommand(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	Command("Start Menu", game, commandRegistry)
{

}

void
StartMenuCommand::execute()
{
	game->setState(State::INITIAL);
}

bool
StartMenuCommand::isActive() {
	if (game->getState() == State::IN_GAME)
	{
		return true;
	}
	else
	{
		return false;
	}
}
