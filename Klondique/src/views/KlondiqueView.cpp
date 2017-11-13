/*
 * KlondiqueView.cpp
 *
 *  Created on: 13 nov. 2017
 *      Author: eseogaz
 */

#include <KlondiqueView.h>

#include "../controllers/OperationController.h"
#include "../controllers/StartController.h"
#include "../controllers/GameController.h"
#include "../controllers/ContinueController.h"

KlondiqueView::KlondiqueView() {
	// TODO Auto-generated constructor stub

}

KlondiqueView::~KlondiqueView() {
	// TODO Auto-generated destructor stub
}

void
KlondiqueView::interact(OperationController* controller)
{
		//assert controller != null;
		controller->accept(this);
}

void
KlondiqueView::visit(StartController* startController)
{
	/*int users = new LimitedIntDialog("Cuántos usuarios?", 0, 2).read();
	startController.setUsers(users);
	new BoardView(startController).write();*/
}

void
KlondiqueView::visit(GameController* gameController)
{
	/*ColorView colorView = new ColorView(gameController.take());
	colorView.writeln("Mueve el jugador ");
	Coordinate origin;
	Error error = null;
	do {
		origin = this.getOrigin(moveController.getCoordinateController());
		error = moveController.validateOrigin(origin);
		if (error != null) {
			io.writeln("" + error);
		}
	} while (error != null);
	moveController.remove(origin);
	Coordinate target;
	error = null;
	do {
		target = this.getTarget("A",
				moveController.getCoordinateController(), origin);
		error = moveController.validateTarget(origin, target);
		if (error != null) {
			io.writeln("" + error);
		}
	} while (error != null);
	moveController.put(target);
	new BoardView(moveController).write();
	if (moveController.existTicTacToe()) {
		colorView.writeWinner();
	}*/
}

void
KlondiqueView::visit(ContinueController* continueController)
{
	/*continueController.setContinue(new YesNoDialog("Desea continuar")
			.read());*/
}

