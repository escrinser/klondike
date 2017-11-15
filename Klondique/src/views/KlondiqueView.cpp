#include <KlondiqueView.h>

#include "../controllers/OperationController.h"
#include "../controllers/StartController.h"
#include "../controllers/GameController.h"
#include "../controllers/ContinueController.h"

KlondiqueView::KlondiqueView()
{
		startView = shared_ptr<StartView>(new StartView());

		gameView = shared_ptr<GameView> (new GameView());

		continueView = shared_ptr<ContinueView> (new ContinueView());
}

KlondiqueView::~KlondiqueView() {
}

void
KlondiqueView::interact(OperationController* controller)
{
		//assert controller != nullptr;
		controller->accept(this);
}

void
KlondiqueView::visit(StartController* startController)
{
	startView->interact(startController);
}

void
KlondiqueView::visit(GameController* gameController)
{
	gameView->interact(gameController);
}

void
KlondiqueView::visit(ContinueController* continueController)
{
	continueView->interact(continueController);
}

