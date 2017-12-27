#ifndef MODELS_STARTMENU_H_
#define MODELS_STARTMENU_H_

#include "Menu.h"

class StartMenu : public Menu{
public:
	StartMenu(shared_ptr<Game> game);
	virtual ~StartMenu();
	void execute();
	bool isClosed();

private:
	shared_ptr<ExitCommand> exitCommand;

	void set();
	void activeStartMenu();
	void deactiveStartMenu();
};

#endif /* MODELS_STARTMENU_H_ */
