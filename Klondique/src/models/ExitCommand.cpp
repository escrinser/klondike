#include <ExitCommand.h>

ExitCommand::ExitCommand(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry) : Command("Exit", game, commandRegistry), closed_(false)
{

}

ExitCommand::~ExitCommand() {

}


void
ExitCommand::execute()
{
	cout << "ExitCommand::execute" << endl;
	game->setState(State::EXIT);
	closed_ = true;
}

bool
ExitCommand::closed()
{
	return closed_;
}

/*Command
ExitCommand::clone()
{
	return this;
}*/

bool
ExitCommand::isActive()
{
	if ((game->getState() == State::INITIAL)
			|| (game->getState() == State::FINAL))
	{
		return true;
	}
	else
	{
		return false;
	}
}
