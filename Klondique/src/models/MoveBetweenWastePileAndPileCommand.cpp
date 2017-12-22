#include <MoveBetweenWastePileAndPileCommand.h>
#include "LimitedInDialog.h"

MoveBetweenWastePileAndPileCommand::~MoveBetweenWastePileAndPileCommand() {
}

MoveBetweenWastePileAndPileCommand::MoveBetweenWastePileAndPileCommand(shared_ptr<Game> game):
	UndoableCommand("MoveBetweenWastePileAndPile", game)
{

}

void
MoveBetweenWastePileAndPileCommand::execute() {
	string titlePileDialog = "Pile Number?";
	game->moveBetweenWastePileAndPile(LimitedInDialog::getInstance()->read(titlePileDialog, MIN_NUMBER_OF_PILES, MAX_NUMBER_OF_PILES));
}

bool
MoveBetweenWastePileAndPileCommand::isActive()
{
	if ((game->getState() == State::IN_GAME)
			&& !game->hasWon())
	{
		return true;
	}
	else
	{
		return false;
	}
}


void
MoveBetweenWastePileAndPileCommand::undo()
{
	game->undo();
}


void
MoveBetweenWastePileAndPileCommand::redo() {
	game->redo();
}

/*UndoableCommand
MoveBetweenWastePileAndPile::clone() {
	MoveCommand moveCommand = new MoveCommand(game);
	moveCommand.origin = origin.clone();
	moveCommand.target = target.clone();
	return moveCommand;
}*/


string
MoveBetweenWastePileAndPileCommand::toString()
{
	return "MoveBetweenWastePileAndPile";
	//return "MoveCommand [origin=" + origin + ", target=" + target + "]";
}
