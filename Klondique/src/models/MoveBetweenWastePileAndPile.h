#ifndef VIEWS_MOVEBETWEENWASTEPILEANDPILE_H_
#define VIEWS_MOVEBETWEENWASTEPILEANDPILE_H_

#include "UndoableCommand.h"

class MoveBetweenWastePileAndPile : public UndoableCommand{
public:
	MoveBetweenWastePileAndPile(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry);

	virtual ~MoveBetweenWastePileAndPile();

	void execute();

	bool isActive();

	void undo();

	void redo();

	//UndoableCommand clone();

	string toString();
};

#endif /* VIEWS_MOVEBETWEENWASTEPILEANDPILE_H_ */
