#ifndef VIEWS_GAMEVIEW_H_
#define VIEWS_GAMEVIEW_H_

class OperationController;
class GameController;

class GameView {
public:
	GameView();
	GameView(OperationController* theController);
	virtual ~GameView();
	void interact(GameController* gameController);
	void saveGame();
	void recoverGame();
private:
	OperationController* controller;
};

#endif /* VIEWS_GAMEVIEW_H_ */
