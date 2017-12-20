/*
 * Command.h
 *
 *  Created on: 19 dic. 2017
 *      Author: eseogaz
 */

#ifndef VIEWS_COMMAND_H_
#define VIEWS_COMMAND_H_

#include "Game.h"
#include "CommandRegistry.h"

class Command {
public:

	Command(std::string title, shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry);
	virtual ~Command();
	std::string getTitle();

	virtual void execute() = 0;
	virtual bool isActive() = 0;

private:
	std::string title;

protected:
	shared_ptr<Game> game;
	shared_ptr<CommandRegistry> commandRegistry;

};

#endif /* VIEWS_COMMAND_H_ */
