#ifndef LOCALCONTINUECONTROLLER_H_
#define LOCALCONTINUECONTROLLER_H_

#include <memory>

#include "../ContinueController.h"
//#include "LocalOperationController.h"

class Game;

using namespace std;

class LocalContinueController : public ContinueController{
public:
	//LocalContinueController(shared_ptr<Game> theGame): LocalOperationController(theGame), game(theGame){};
	LocalContinueController(shared_ptr<Game> theGame): ContinueController(), game(theGame){};
	virtual ~LocalContinueController();
	void setContinue(int theOption);
	void accept(OperationControllerVisitor* operationControllerVisitor);
	void clear();
	void setState(State state);
	void printBoard();
private:
	shared_ptr<Game> game;
};

#endif /* LOCALCONTINUECONTROLLER_H_ */
