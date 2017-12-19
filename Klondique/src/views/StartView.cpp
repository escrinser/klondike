#include <StartView.h>

#include "../controllers/StartController.h"

#include "../utils/LimitedInDialog.h"

#include "BoardView.h"

#include "GameView.h"

StartView::StartView() {

}

StartView::~StartView() {
}

void
StartView::interact(StartController* startController)
{
	LimitedInDialog startDialog ("Chose one option:\n\n"
				"1  Play\n"
			    "2  Recover game from file\n"
			    "3  Exit\n"
				"Enter your choice and press return:", MENU_OPTION_1, MENU_OPTION_3);

	switch (startDialog.read())
	{
	   case 1:
		   startController->setStart();
		   startController->setState(State::IN_GAME);
		   BoardView(startController).showBoard();
		   break;

	   case 2: //Recover this game from file
		   GameView(startController).recoverGame();
		   startController->setState(State::IN_GAME);
		   BoardView(startController).showBoard();
		   break;

	   case 3:
		   startController->setState(State::EXIT);
		   break;

	   default:
		   break;
	}
}

