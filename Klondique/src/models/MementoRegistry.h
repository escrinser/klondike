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
	MementoRegistry();

	virtual ~MementoRegistry();

	MementoRegistry(shared_ptr<Game> game);

	void registry();

	void undo(shared_ptr<Game> game);

	void redo(shared_ptr<Game> game);

private:
	shared_ptr<Game> game;

	vector<shared_ptr<GameMemento>> mementoList;
};

#endif /* MODELS_MEMENTOREGISTRY_H_ */
