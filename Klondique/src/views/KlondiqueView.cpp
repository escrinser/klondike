#include <KlondiqueView.h>

#include "../controllers/OperationController.h"
#include "../controllers/StartController.h"
#include "../controllers/GameController.h"
#include "../controllers/ContinueController.h"

#include "Menu.h"

KlondiqueView::KlondiqueView()
{
	    //menu = new Menu(shared_ptr<Game>(new Game()));
	    menuView = shared_ptr<MenuView>(new MenuView());

	    startView = shared_ptr<StartView>(new StartView());

		gameView = shared_ptr<GameView> (new GameView());

		continueView = shared_ptr<ContinueView> (new ContinueView());
}

KlondiqueView::~KlondiqueView() {
}

void
KlondiqueView::interact(OperationController* controller)
{
		controller->accept(this);
}

void
KlondiqueView::interact(Menu* menu)
{
		menu->accept(this);
}

void
KlondiqueView::visit(Menu* menu)
{
	menuView->interact(menu);
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

