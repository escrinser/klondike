#ifndef VIEWS_MOVEBETWEENWASTEPILEANDFOUNDATION_H_
#define VIEWS_MOVEBETWEENWASTEPILEANDFOUNDATION_H_

#include <UndoRedoAbleCommand.h>

class MoveBetweenWastePileAndFoundationCommand : public UndoRedoAbleCommand{
public:
	MoveBetweenWastePileAndFoundationCommand(shared_ptr<Game> game);

	virtual ~MoveBetweenWastePileAndFoundationCommand();

	void execute();

	bool isActive();

	void undo();

	void redo();

	string toString();
};

#endif /* VIEWS_MOVEBETWEENWASTEPILEANDFOUNDATION_H_ */
