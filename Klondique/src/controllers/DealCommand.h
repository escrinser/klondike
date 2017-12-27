#ifndef MODELS_DEALCOMMAND_H_
#define MODELS_DEALCOMMAND_H_

#include <UndoRedoAbleCommand.h>

class DealCommand : public UndoRedoAbleCommand{
public:
	DealCommand(shared_ptr<Game> game);

	virtual ~DealCommand();

	void execute();

	bool isActive();

	void undo();

	void redo();

	string toString();
};

#endif /* MODELS_DEALCOMMAND_H_ */
