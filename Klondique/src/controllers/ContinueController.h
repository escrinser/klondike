#ifndef CONTINUECONTROLLER_H_
#define CONTINUECONTROLLER_H_

#include <memory>
#include "OperationController.h"
#include "OperationControllerVisitor.h"


class Game;

using namespace std;

class ContinueController : public OperationController{
public:
	ContinueController(shared_ptr<Game> theGame): OperationController(theGame), game(theGame){};
	virtual ~ContinueController();
	void setContinue(int theOption);
	void accept(OperationControllerVisitor* operationControllerVisitor);
private:
	shared_ptr<Game> game;
};

#endif /* CONTINUECONTROLLER_H_ */
