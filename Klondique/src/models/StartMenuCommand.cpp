#include <StartMenuCommand.h>

StartMenuCommand::~StartMenuCommand() {

}

StartMenuCommand::StartMenuCommand(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	Command("Start Menu", game, commandRegistry)
{

}

void
StartMenuCommand::execute() {

}

bool
StartMenuCommand::isActive() {
	if (game->getState() == State::INITIAL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
