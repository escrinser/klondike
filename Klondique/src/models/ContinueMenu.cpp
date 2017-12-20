#include <ContinueMenu.h>
#include "PlayCommand.h"
#include "ContinueCommand.h"
#include "SaveGameCommand.h"

ContinueMenu::ContinueMenu(shared_ptr<Game> game): Menu(game) {
	allCommandList.push_back(shared_ptr<PlayCommand>(new PlayCommand(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<ContinueCommand>(new ContinueCommand(game, commandRegistry)));
    allCommandList.push_back(shared_ptr<SaveGameCommand>(new SaveGameCommand(game, commandRegistry)));
	allCommandList.push_back(exitCommand);
}

ContinueMenu::~ContinueMenu() {

}

