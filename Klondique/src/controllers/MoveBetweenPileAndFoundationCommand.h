#ifndef MODELS_MOVEBETWEENPILEANDFOUNDATIONCOMMAND_H_
#define MODELS_MOVEBETWEENPILEANDFOUNDATIONCOMMAND_H_

#include <UndoRedoAbleCommand.h>

class MoveBetweenPileAndFoundationCommand : public UndoRedoAbleCommand{
public:
	MoveBetweenPileAndFoundationCommand(shared_ptr<Game> game);

	virtual ~MoveBetweenPileAndFoundationCommand();

	void execute();

	bool isActive();

	void undo();

	void redo();

	string toString();
};
#endif /* MODELS_MOVEBETWEENPILEANDFOUNDATIONCOMMAND_H_ */
