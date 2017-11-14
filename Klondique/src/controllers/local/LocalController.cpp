#include <LocalController.h>

#include "../../models/State.h"
#include "../../models/Game.h"

LocalController::LocalController(shared_ptr<Game> theGame) {
	game = theGame;
}

LocalController::~LocalController() {
	// TODO Auto-generated destructor stub
}

State LocalController::getState() {
	return game->getState();
}

void LocalController::setState(State state) {
	game->setState(state);
}

void LocalController::clear() {
	game->clear();
}

shared_ptr<Game> LocalController::getGame() {
	return game;
}

void
LocalController::printBoard()
{
	game->showBoard();
}
