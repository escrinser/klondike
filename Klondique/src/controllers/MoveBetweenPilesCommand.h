#ifndef MODELS_MOVEBETWEENPILESCOMMAND_H_
#define MODELS_MOVEBETWEENPILESCOMMAND_H_

#include "UndoableCommand.h"

class MoveBetweenPilesCommand : public UndoableCommand{
public:
	MoveBetweenPilesCommand(shared_ptr<Game> game);

	virtual ~MoveBetweenPilesCommand();

	void execute();

	bool isActive();

	void undo();

	void redo();

	string toString();
};

#endif /* MODELS_MOVEBETWEENPILESCOMMAND_H_ */
