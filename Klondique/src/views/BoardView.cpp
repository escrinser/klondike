#include <BoardView.h>

#include <../controllers/OperationController.h>

BoardView::BoardView(OperationController* theController)
{
	controller = theController;
}

BoardView::~BoardView() {
}

void
BoardView::showBoard()
{
	controller->printBoard();
}
