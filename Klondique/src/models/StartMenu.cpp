#include <StartMenu.h>
#include "PlayCommand.h"
#include "RecoverGameCommand.h"

StartMenu::StartMenu(shared_ptr<Game> game):Menu(game)
{

}

StartMenu::~StartMenu() {

}

void
StartMenu::set(){
	if ((game->getState() == State::INITIAL)
			|| (game->getState() == State::FINAL))
	{
		activeStartMenu();
	} else {
		deactiveStartMenu();
	}
}

void
StartMenu::activeStartMenu() {
	allCommandList.clear();
	allCommandList.push_back(shared_ptr<PlayCommand>(new PlayCommand(game, commandRegistry)));
    allCommandList.push_back(shared_ptr<RecoverGameCommand>(new RecoverGameCommand(game, commandRegistry)));
	allCommandList.push_back(exitCommand);
}

void
StartMenu::deactiveStartMenu() {
	allCommandList.clear();
    allCommandList.push_back(exitCommand);
}

void
StartMenu::execute() {
	exitCommand.reset();
	do {
		set();
		execute();
	} while (!exitCommand->closed());
}

bool
StartMenu::isClosed() {
	return exitCommand->closed();
}
