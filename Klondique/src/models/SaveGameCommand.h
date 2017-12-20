#ifndef MODELS_SAVEGAMECOMMAND_H_
#define MODELS_SAVEGAMECOMMAND_H_

#include "Command.h"

class SaveGameCommand : public Command{
public:
	SaveGameCommand(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry);

	virtual ~SaveGameCommand();

	void execute();

	bool isActive();

};

#endif /* MODELS_SAVEGAMECOMMAND_H_ */
