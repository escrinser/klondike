/*
 * MememtoRegistry.cpp
 *
 *  Created on: 12 dic. 2017
 *      Author: eseogaz
 */

#include <MementoRegistry.h>

MementoRegistry::MementoRegistry() {
	// TODO Auto-generated constructor stub

}

MementoRegistry::~MementoRegistry() {
	// TODO Auto-generated destructor stub
}

MementoRegistry::MementoRegistry(shared_ptr<Game> game)
{
	this->game = game;
	//mementoList = new vector<shared_ptr<GameMemento>>();
	mementoList.push_back(game->createMemento());
}

void
MementoRegistry::registry()
{
	/*for (int i = 0; i < firstPrevious; i++) {
		mementoList.pop_back(0);
	}*/
	//firstPrevious = 0;
	mementoList.push_back(game->createMemento());
}

void
MementoRegistry::undo(shared_ptr<Game> game)
{
	//firstPrevious++;
	game->set(mementoList.back());
}

void
MementoRegistry::redo(shared_ptr<Game> game)
{
	//firstPrevious--;
	game->set(mementoList[0]);
}



