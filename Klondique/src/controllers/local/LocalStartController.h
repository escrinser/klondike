#ifndef LOCALSTARTCONTROLLER_H_
#define LOCALSTARTCONTROLLER_H_

#include <memory>

#include "StartController.h"
#include "LocalOperationController.h"

class Game;

using namespace std;

class LocalStartController : public StartController,  LocalOperationController{
public:
	LocalStartController(shared_ptr<Game> theGame): LocalOperationController(theGame), game(theGame){};
	virtual ~LocalStartController();
	void setStart(State theState);
	void accept(OperationControllerVisitor* operationControllerVisitor);

private:
	shared_ptr<Game> game;
};

#endif /* LOCALSTARTCONTROLLER_H_ */
