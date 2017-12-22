#ifndef MODELS_MOVEBETWEENPILEANDFOUNDATIONCOMMAND_H_
#define MODELS_MOVEBETWEENPILEANDFOUNDATIONCOMMAND_H_

#include "UndoableCommand.h"

class MoveBetweenPileAndFoundationCommand : public UndoableCommand{
public:
	MoveBetweenPileAndFoundationCommand(shared_ptr<Game> game);

	virtual ~MoveBetweenPileAndFoundationCommand();

	void execute();

	bool isActive();

	void undo();

	void redo();

	//UndoableCommand clone();

	string toString();
};
#endif /* MODELS_MOVEBETWEENPILEANDFOUNDATIONCOMMAND_H_ */
