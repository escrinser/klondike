#include <PlayCommand.h>

PlayCommand::~PlayCommand() {

}

PlayCommand::PlayCommand(shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	Command("Play", game, commandRegistry)
{

}

void
PlayCommand::execute()
{
	game->startPlayingBoard();
	game->setState(State::IN_GAME);
}

bool
PlayCommand::isActive() {
	if (game->getState() == State::INITIAL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
