#include <PlayCommand.h>

PlayCommand::~PlayCommand() {

}

PlayCommand::PlayCommand(shared_ptr<Game> game):
	Command("Play", game)
{

}

void
PlayCommand::execute()
{
	cout << "PlayCommand::execute" << endl;
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
