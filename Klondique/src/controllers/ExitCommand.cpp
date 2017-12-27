#include <ExitCommand.h>

ExitCommand::ExitCommand(shared_ptr<Game> game) : Command("Exit", game), closed_(false)
{

}

ExitCommand::~ExitCommand() {

}


void
ExitCommand::execute()
{
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
