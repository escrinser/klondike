#include <SaveGameCommand.h>

SaveGameCommand::~SaveGameCommand() {

}

SaveGameCommand::SaveGameCommand(shared_ptr<Game> game):
	Command("Save game", game)
{

}

void
SaveGameCommand::execute()
{
	game->saveGame();
}

bool
SaveGameCommand::isActive()
{
	if (game->getState() == State::FINAL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
