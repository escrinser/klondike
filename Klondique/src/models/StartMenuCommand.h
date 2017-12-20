#ifndef MODELS_STARTMENUCOMMAND_H_
#define MODELS_STARTMENUCOMMAND_H_

#include "Command.h"

class StartMenuCommand : public Command{
public:
	StartMenuCommand(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry);

	virtual ~StartMenuCommand();

	void execute();

	bool isActive();

};

#endif /* MODELS_STARTMENUCOMMAND_H_ */
