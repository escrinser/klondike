#ifndef MODELS_EXITCOMMAND_H_
#define MODELS_EXITCOMMAND_H_

#include "Command.h"

class ExitCommand : public Command {
public:
	ExitCommand();
	virtual ~ExitCommand();
	void execute();

	bool closed();

	//Command clone();

	bool isActive();

private:
	bool closed_;

};

#endif /* MODELS_EXITCOMMAND_H_ */
