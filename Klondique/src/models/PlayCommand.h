#ifndef MODELS_PLAYCOMMAND_H_
#define MODELS_PLAYCOMMAND_H_

#include "Command.h"

class PlayCommand : public Command{
public:
	PlayCommand(shared_ptr<Game> game);

	virtual ~PlayCommand();

	void execute();

	bool isActive();

};

#endif /* MODELS_PLAYCOMMAND_H_ */
