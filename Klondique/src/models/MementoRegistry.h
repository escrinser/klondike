/*
 * MememtoRegistry.h
 *
 *  Created on: 12 dic. 2017
 *      Author: eseogaz
 */

#ifndef MODELS_MEMENTOREGISTRY_H_
#define MODELS_MEMENTOREGISTRY_H_

#include "Game.h"

#include <vector>

class MementoRegistry {
public:
	virtual ~MementoRegistry();

	MementoRegistry(Game* game);

	void registry();

	void undo(Game game);

	void redo(Game game);


	void SaveState();

	void RestoreState(int stateNumber);

private:
	Game* game;

	vector<shared_ptr<GameMemento>> mementoList;

	int firstPrevious;

};

#endif /* MODELS_MEMENTOREGISTRY_H_ */
