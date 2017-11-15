#include "LocalController.h"

#include "../../models/State.h"
#include "../../models/Game.h"

LocalController::LocalController(shared_ptr<Game> theGame) {
	game = theGame;
}

LocalController::~LocalController() {
	// TODO Auto-generated destructor stub
}

void LocalController::setState(State state) {
	game->setState(state);
}

void LocalController::clear() {
	game->clear();
}

void
LocalController::printBoard()
{
	game->showBoard();
}
