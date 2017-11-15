#ifndef VIEWS_GAMEVIEW_H_
#define VIEWS_GAMEVIEW_H_

class GameController;

class GameView {
public:
	GameView();
	virtual ~GameView();
	void interact(GameController* gameController);
};

#endif /* VIEWS_GAMEVIEW_H_ */
