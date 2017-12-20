#include <GameMenu.h>
#include "DealCommand.h"
#include "MoveBetweenPileAndFoundation.h"
#include "MoveBetweenWastePileAndPile.h"
#include "MoveBetweenWastePileAndFoundation.h"
#include "MoveBetweenPiles.h"
#include "StartMenuCommand.h"


GameMenu::GameMenu(shared_ptr<Game> game):Menu(game)
{
	allCommandList.push_back(shared_ptr<DealCommand>(new DealCommand(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<MoveBetweenPileAndFoundation>(new MoveBetweenPileAndFoundation(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<MoveBetweenWastePileAndPile>(new MoveBetweenWastePileAndPile(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<MoveBetweenWastePileAndFoundation>(new MoveBetweenWastePileAndFoundation(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<MoveBetweenPiles>(new MoveBetweenPiles(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<StartMenuCommand>(new StartMenuCommand(game, commandRegistry)));
    allCommandList.push_back(exitCommand);
}

GameMenu::~GameMenu() {
}

