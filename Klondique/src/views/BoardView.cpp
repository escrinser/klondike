/*
 * BoardView.cpp
 *
 *  Created on: 13 nov. 2017
 *      Author: eseogaz
 */

#include <BoardView.h>

#include "OperationController.h"

BoardView::BoardView(OperationController* theController)
{
	//assert theController != nullptr;

	controller = theController;
}

BoardView::~BoardView() {
	// TODO Auto-generated destructor stub
}

void
BoardView::showBoard()
{
	controller->printBoard();

}
