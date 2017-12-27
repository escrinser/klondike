#ifndef VIEWS_MOVEBETWEENWASTEPILEANDPILE_H_
#define VIEWS_MOVEBETWEENWASTEPILEANDPILE_H_

#include <UndoRedoAbleCommand.h>

class MoveBetweenWastePileAndPileCommand : public UndoRedoAbleCommand{
public:
	MoveBetweenWastePileAndPileCommand(shared_ptr<Game> game);

	virtual ~MoveBetweenWastePileAndPileCommand();

	void execute();

	bool isActive();

	void undo();

	void redo();

	string toString();
};

#endif /* VIEWS_MOVEBETWEENWASTEPILEANDPILE_H_ */
