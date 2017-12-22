#ifndef MODELS_MOVEBETWEENPILES_H_
#define MODELS_MOVEBETWEENPILES_H_

#include "UndoableCommand.h"

class MoveBetweenPiles : public UndoableCommand{
public:
	MoveBetweenPiles(shared_ptr<Game> game);

	virtual ~MoveBetweenPiles();

	void execute();

	bool isActive();

	void undo();

	void redo();

	//UndoableCommand clone();

	string toString();
};

#endif /* MODELS_MOVEBETWEENPILES_H_ */
