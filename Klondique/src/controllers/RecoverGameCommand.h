#ifndef MODELS_RECOVERGAMECOMMAND_H_
#define MODELS_RECOVERGAMECOMMAND_H_

#include "Command.h"

class RecoverGameCommand : public Command{
public:
	RecoverGameCommand(shared_ptr<Game> game);

	virtual ~RecoverGameCommand();

	void execute();

	bool isActive();

};

#endif /* MODELS_RECOVERGAMECOMMAND_H_ */
