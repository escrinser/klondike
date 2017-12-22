#ifndef VIEWS_COMMAND_H_
#define VIEWS_COMMAND_H_

#include "Game.h"

class Command {
public:

	Command(std::string title, shared_ptr<Game> game);
	virtual ~Command();
	std::string getTitle();

	virtual void execute() = 0;
	virtual bool isActive() = 0;

private:
	std::string title;

protected:
	shared_ptr<Game> game;

};

#endif /* VIEWS_COMMAND_H_ */
