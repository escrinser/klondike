#ifndef MODELS_DEALCOMMAND_H_
#define MODELS_DEALCOMMAND_H_

#include "UndoableCommand.h"

class DealCommand : public UndoableCommand{
public:
	DealCommand(shared_ptr<Game> game);

	virtual ~DealCommand();

	void execute();

	bool isActive();

	void undo();

	void redo();

	//UndoableCommand clone();

	string toString();
};

#endif /* MODELS_DEALCOMMAND_H_ */
