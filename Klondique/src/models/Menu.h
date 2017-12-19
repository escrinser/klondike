/*
 * Menu.h
 *
 *  Created on: 19 dic. 2017
 *      Author: eseogaz
 */

#ifndef MODELS_MENU_H_
#define MODELS_MENU_H_

#include "Game.h"
#include "Command.h"
#include "ExitCommand.h"

class Menu {
public:
	Menu(shared_ptr<Game> game);
	virtual ~Menu();
	void execute();

private:
	shared_ptr<Game> game;

	shared_ptr<CommandRegistry> commandRegistry;

	vector<shared_ptr<Command>> allCommandList;

	shared_ptr<ExitCommand> exitCommand;

	vector<shared_ptr<Command>> actualCommandList;

	void setActualCommands();

	void write();

	int getOption();

	bool isClosed();
};

#endif /* MODELS_MENU_H_ */
