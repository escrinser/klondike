#ifndef MODELS_MEMENTOREGISTRY_H_
#define MODELS_MEMENTOREGISTRY_H_

#include "Game.h"

#include <vector>

class MementoRegistry {
public:
	virtual ~MementoRegistry();

	MementoRegistry(shared_ptr<Game> game);

	MementoRegistry();

	void registry();

	void undo();

	void redo();

private:
	shared_ptr<Game> game;

	vector<shared_ptr<GameMemento>> mementoList;

	unsigned int redoUndoIndex = 0;

};

#endif /* MODELS_MEMENTOREGISTRY_H_ */
