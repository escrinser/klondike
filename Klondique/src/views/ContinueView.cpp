#include <ContinueView.h>

#include "../controllers/ContinueController.h"

#include "../utils/LimitedInDialog.h"

#include "BoardView.h"

ContinueView::ContinueView() {

}

ContinueView::~ContinueView() {
}

void
ContinueView::interact(ContinueController* continueController)
{
	string title = "Chose one option:\n\n"
			"1  Play again\n"
			"2  Continue\n"
			"3  Save game to file\n"
			"4  Exit\n"
			"Enter your choice and press return:";
	int option = LimitedInDialog::getInstance()->read(title, MENU_OPTION_1, MENU_OPTION_4);
	continueController->setContinue(option);
}

