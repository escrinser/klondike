#include <StartView.h>

#include "../controllers/StartController.h"

#include "../utils/LimitedInDialog.h"

#include "BoardView.h"

StartView::StartView() {

}

StartView::~StartView() {
}

void
StartView::interact(StartController* startController)
{
	LimitedInDialog startDialog ("Chose one option:\n\n"
				"1  Play\n"
				"2  Exit\n"
				"Enter your choice and press return:", MENU_OPTION_1, MENU_OPTION_2);

	switch (startDialog.read())
	{
	   case 1:
		   startController->setStart();
		   startController->setState(State::IN_GAME);
		   BoardView(startController).showBoard();
		   break;

	   case 2:
		   startController->setState(State::EXIT);
		   break;

	   default:
		   break;
	}
}

