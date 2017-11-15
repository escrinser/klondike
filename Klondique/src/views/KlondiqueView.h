#ifndef VIEWS_KLONDIQUEVIEW_H_
#define VIEWS_KLONDIQUEVIEW_H_

#include <memory>

#include "../controllers/OperationControllerVisitor.h"
#include "StartView.h"
#include "GameView.h"
#include "ContinueView.h"

class OperationController;
class StartController;
class GameController;
class ContinueController;

using namespace std;

class KlondiqueView : public OperationControllerVisitor{
public:
	KlondiqueView();
	virtual ~KlondiqueView();
	void interact(OperationController* controller);
	void visit(StartController* startController);
	void visit(GameController* gameController);
	void visit(ContinueController* continueController);
private:
	shared_ptr<StartView> startView;
	shared_ptr<GameView> gameView;
	shared_ptr<ContinueView> continueView;
};

#endif /* VIEWS_KLONDIQUEVIEW_H_ */
