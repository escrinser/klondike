#include <DealCommand.h>

DealCommand::~DealCommand() {

}

DealCommand::DealCommand(shared_ptr<Game> game):
	UndoableCommand("Deal", game)
{

}

void
DealCommand::execute()
{
	game->deal();
}

bool
DealCommand::isActive()
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
DealCommand::undo()
{
	game->undo();
}


void
DealCommand::redo() {
	game->redo();
}

/*UndoableCommand
DealCommand::clone() {
	MoveCommand moveCommand = new MoveCommand(game);
	moveCommand.origin = origin.clone();
	moveCommand.target = target.clone();
	return moveCommand;
}*/


string
DealCommand::toString()
{
	return "DealCommand";
	//return "MoveCommand [origin=" + origin + ", target=" + target + "]";
}

