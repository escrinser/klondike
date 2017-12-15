#ifndef VIEWS_BOARDVIEW_H_
#define VIEWS_BOARDVIEW_H_

class OperationController;

#define MENU_OPTION_1 1
#define MENU_OPTION_2 2
#define MENU_OPTION_3 3
#define MENU_OPTION_6 6
#define MENU_OPTION_7 7
#define MENU_OPTION_8 8

#define MIN_NUMBER_OF_CARDS 1
#define MAX_NUMBER_OF_CARDS 13

#define MIN_NUMBER_OF_PILES 1
#define MAX_NUMBER_OF_PILES 7

class BoardView {
public:
	BoardView(OperationController* controller);
	virtual ~BoardView();
	void showBoard();
private:
	OperationController* controller;
};

#endif /* VIEWS_BOARDVIEW_H_ */
