#ifndef VIEWS_MOVEBETWEENWASTEPILEANDFOUNDATION_H_
#define VIEWS_MOVEBETWEENWASTEPILEANDFOUNDATION_H_

#include "UndoableCommand.h"

class MoveBetweenWastePileAndFoundation : public UndoableCommand{
public:
	MoveBetweenWastePileAndFoundation(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry);

	virtual ~MoveBetweenWastePileAndFoundation();

	void execute();

	bool isActive();

	void undo();

	void redo();

	//UndoableCommand clone();

	string toString();
};

#endif /* VIEWS_MOVEBETWEENWASTEPILEANDFOUNDATION_H_ */
