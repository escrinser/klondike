/*
 * ExitCommand.cpp
 *
 *  Created on: 19 dic. 2017
 *      Author: eseogaz
 */

#include <ExitCommand.h>

ExitCommand::ExitCommand() : Command("Exit", nullptr, nullptr), closed_(false)
{

}

ExitCommand::~ExitCommand() {
	// TODO Auto-generated destructor stub
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
