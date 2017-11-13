#ifndef STARTCONTROLLER_H_
#define STARTCONTROLLER_H_

#include <memory>
#include "OperationController.h"

class Game;

using namespace std;

class StartController : public OperationController {
public:
	StartController(shared_ptr<Game> theGame): OperationController(theGame), game(theGame){};
	virtual ~StartController();
	void setStart(State theState);
	void accept(OperationControllerVisitor* operationControllerVisitor);
private:
	shared_ptr<Game> game;
};

#endif /* STARTCONTROLLER_H_ */
