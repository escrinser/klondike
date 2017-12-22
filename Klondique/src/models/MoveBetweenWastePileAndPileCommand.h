#ifndef VIEWS_MOVEBETWEENWASTEPILEANDPILE_H_
#define VIEWS_MOVEBETWEENWASTEPILEANDPILE_H_

#include "UndoableCommand.h"

class MoveBetweenWastePileAndPileCommand : public UndoableCommand{
public:
	MoveBetweenWastePileAndPileCommand(shared_ptr<Game> game);

	virtual ~MoveBetweenWastePileAndPileCommand();

	void execute();

	bool isActive();

	void undo();

	void redo();

	//UndoableCommand clone();

	string toString();
};

#endif /* VIEWS_MOVEBETWEENWASTEPILEANDPILE_H_ */
