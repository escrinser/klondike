#ifndef LOCALSTARTCONTROLLER_H_
#define LOCALSTARTCONTROLLER_H_

#include <memory>

#include "../StartController.h"
//#include "../OperationController.h"

class Game;

using namespace std;

class LocalStartController : public StartController{
public:
	//LocalStartController(shared_ptr<Game> theGame): LocalOperationController(), game(theGame){};
	LocalStartController(shared_ptr<Game> theGame): StartController(), game(theGame){};
	virtual ~LocalStartController();
	void setStart(State theState);
	void accept(OperationControllerVisitor* operationControllerVisitor);

private:
	shared_ptr<Game> game;
};

#endif /* LOCALSTARTCONTROLLER_H_ */
