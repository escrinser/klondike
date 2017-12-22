#ifndef MODELS_CONTINUEMENUCOMMAND_H_
#define MODELS_CONTINUEMENUCOMMAND_H_

#include "Command.h"

class ContinueMenuCommand : public Command{
public:
	ContinueMenuCommand(shared_ptr<Game> game);

	virtual ~ContinueMenuCommand();

	void execute();

	bool isActive();

};

#endif /* MODELS_CONTINUEMENUCOMMAND_H_ */
