#ifndef VIEWS_BOARDVIEW_H_
#define VIEWS_BOARDVIEW_H_

class OperationController;

class BoardView {
public:
	BoardView(OperationController* controller);
	virtual ~BoardView();
	void showBoard();
private:
	OperationController* controller;
};

#endif /* VIEWS_BOARDVIEW_H_ */
