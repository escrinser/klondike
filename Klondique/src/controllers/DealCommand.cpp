#include <DealCommand.h>

DealCommand::~DealCommand() {

}

DealCommand::DealCommand(shared_ptr<Game> game):
	UndoRedoAbleCommand("Deal", game)
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


string
DealCommand::toString()
{
	return "DealCommand";
}

