#ifndef MODELS_COMMANDREGISTRY_H_
#define MODELS_COMMANDREGISTRY_H_

#include "Game.h"

#include <vector>

class CommandRegistry {
public:
	virtual ~CommandRegistry();

	CommandRegistry(shared_ptr<Game> game);

	CommandRegistry();

	void registry();

	void undo();

	void redo();

private:
	shared_ptr<Game> game;

	vector<shared_ptr<GameMemento>> commandList;

	unsigned int redoUndoIndex = 0;

};

#endif /* MODELS_COMMANDREGISTRY_H_ */
