#include <SaveGameCommand.h>

SaveGameCommand::~SaveGameCommand() {

}

SaveGameCommand::SaveGameCommand(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	Command("Save game", game, commandRegistry)
{

}

void
SaveGameCommand::execute()
{
	game->saveGame();
	game->setState(State::EXIT); //Save the game and Exit.
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
