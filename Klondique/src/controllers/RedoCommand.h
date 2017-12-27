#ifndef MODELS_REDOCOMMAND_H_
#define MODELS_REDOCOMMAND_H_

#include "Command.h"

class RedoCommand : public Command{
public:
	RedoCommand(shared_ptr<Game> game);

	virtual ~RedoCommand();

	void execute();

	bool isActive();

};

#endif /* MODELS_REDOCOMMAND_H_ */
