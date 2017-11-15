#include <BoardView.h>

#include <../controllers/OperationController.h>

BoardView::BoardView(OperationController* theController)
{
	//assert theController != nullptr;

	controller = theController;
}

BoardView::~BoardView() {
}

void
BoardView::showBoard()
{
	controller->printBoard();
}
