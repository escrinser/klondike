#ifndef LOCALSTARTCONTROLLER_H_
#define LOCALSTARTCONTROLLER_H_

#include <memory>

#include "../StartController.h"

class Game;

using namespace std;

class LocalStartController : public StartController{
public:
	LocalStartController(shared_ptr<Game> theGame): StartController(), game(theGame){};
	virtual ~LocalStartController();
	void setStart();
	void accept(OperationControllerVisitor* operationControllerVisitor);
	void setState(State state);
	void printBoard();

	void saveGame();
	void recoverGame();
private:
	shared_ptr<Game> game;
};

#endif /* LOCALSTARTCONTROLLER_H_ */
