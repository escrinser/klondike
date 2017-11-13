/*
 * KlondiqueView.h
 *
 *  Created on: 13 nov. 2017
 *      Author: eseogaz
 */

#ifndef VIEWS_KLONDIQUEVIEW_H_
#define VIEWS_KLONDIQUEVIEW_H_

#include "OperationControllerVisitor.h"
#include <memory>


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
};

#endif /* VIEWS_KLONDIQUEVIEW_H_ */
