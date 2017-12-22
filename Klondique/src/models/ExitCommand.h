#ifndef MODELS_EXITCOMMAND_H_
#define MODELS_EXITCOMMAND_H_

#include "Command.h"

class ExitCommand : public Command {
public:
	ExitCommand(shared_ptr<Game> game);
	virtual ~ExitCommand();
	void execute();

	bool closed();

	//Command clone();

	bool isActive();

private:
	bool closed_;

};

#endif /* MODELS_EXITCOMMAND_H_ */
