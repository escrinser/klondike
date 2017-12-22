#ifndef MODELS_MOVEBETWEENPILEANDFOUNDATION_H_
#define MODELS_MOVEBETWEENPILEANDFOUNDATION_H_

#include "UndoableCommand.h"

class MoveBetweenPileAndFoundation : public UndoableCommand{
public:
	MoveBetweenPileAndFoundation(shared_ptr<Game> game);

	virtual ~MoveBetweenPileAndFoundation();

	void execute();

	bool isActive();

	void undo();

	void redo();

	//UndoableCommand clone();

	string toString();
};
#endif /* MODELS_MOVEBETWEENPILEANDFOUNDATION_H_ */
