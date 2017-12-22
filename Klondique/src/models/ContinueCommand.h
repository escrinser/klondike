#ifndef MODELS_CONTINUECOMMAND_H_
#define MODELS_CONTINUECOMMAND_H_

#include "Command.h"

class ContinueCommand : public Command{
public:
	ContinueCommand(shared_ptr<Game> game);

	virtual ~ContinueCommand();

	void execute();

	bool isActive();

};

#endif /* MODELS_CONTINUECOMMAND_H_ */
