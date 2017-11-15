#include <ContinueView.h>

#include "../controllers/ContinueController.h"

#include "../utils/LimitedInDialog.h"

ContinueView::ContinueView() {

}

ContinueView::~ContinueView() {
}

void
ContinueView::interact(ContinueController* continueController)
{
	LimitedInDialog continueMenuDialog ("Chose one option:\n\n"
			"1  Play again\n"
			"2  Continue\n"
			"3  Exit\n"
			"Enter your choice and press return:", 1, 3);

	continueController->setContinue(continueMenuDialog.read());
}

