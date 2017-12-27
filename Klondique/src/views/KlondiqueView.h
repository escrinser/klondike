#ifndef VIEWS_KLONDIQUEVIEW_H_
#define VIEWS_KLONDIQUEVIEW_H_

#include <memory>

#include "../controllers/OperationControllerVisitor.h"
#include "StartView.h"
#include "GameView.h"
#include "ContinueView.h"

#include "../controllers/MenuVisitor.h"
#include "MenuView.h"
class Menu;


class OperationController;
class StartController;
class GameController;
class ContinueController;

using namespace std;

class KlondiqueView : public OperationControllerVisitor, MenuVisitor{
public:
	KlondiqueView();
	virtual ~KlondiqueView();
	void interact(OperationController* controller);

	void interact(Menu* menu);
	void visit(Menu* menu);

	void visit(StartController* startController);
	void visit(GameController* gameController);
	void visit(ContinueController* continueController);
private:
	shared_ptr<StartView> startView;
	shared_ptr<GameView> gameView;
	shared_ptr<ContinueView> continueView;

	shared_ptr<MenuView> menuView;
};

#endif /* VIEWS_KLONDIQUEVIEW_H_ */
