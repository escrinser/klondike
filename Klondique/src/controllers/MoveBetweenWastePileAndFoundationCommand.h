#ifndef VIEWS_MOVEBETWEENWASTEPILEANDFOUNDATION_H_
#define VIEWS_MOVEBETWEENWASTEPILEANDFOUNDATION_H_

#include "UndoableCommand.h"

class MoveBetweenWastePileAndFoundationCommand : public UndoableCommand{
public:
	MoveBetweenWastePileAndFoundationCommand(shared_ptr<Game> game);

	virtual ~MoveBetweenWastePileAndFoundationCommand();

	void execute();

	bool isActive();

	void undo();

	void redo();

	//UndoableCommand clone();

	string toString();
};

#endif /* VIEWS_MOVEBETWEENWASTEPILEANDFOUNDATION_H_ */
