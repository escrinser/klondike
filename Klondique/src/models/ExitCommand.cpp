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
	return true;
}
