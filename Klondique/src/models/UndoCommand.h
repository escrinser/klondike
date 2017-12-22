#ifndef MODELS_UNDOCOMMAND_H_
#define MODELS_UNDOCOMMAND_H_

#include "Command.h"

class UndoCommand : public Command{
public:
	UndoCommand(shared_ptr<Game> game);

	virtual ~UndoCommand();

	void execute();

	bool isActive();

};


#endif /* MODELS_UNDOCOMMAND_H_ */
