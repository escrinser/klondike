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

protected:
	vector<shared_ptr<Command>> allCommandList;

	shared_ptr<ExitCommand> exitCommand;

	shared_ptr<Game> game;

	void write();

	int getOption();

private:

	vector<shared_ptr<Command>> actualCommandList;

	void setActualCommands();

	bool isClosed();
};

#endif /* MODELS_MENU_H_ */
