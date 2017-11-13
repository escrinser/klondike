#ifndef OPERATIONCONTROLLER_H_
#define OPERATIONCONTROLLER_H_

#include <memory>

#include "Controller.h"
#include "OperationControllerVisitor.h"

class Game;
class KlondiqueView;

using namespace std;

class OperationController : public Controller {
public:
	OperationController(shared_ptr<Game> theGame): Controller(theGame), game(theGame){};
	virtual ~OperationController();
	virtual void accept(OperationControllerVisitor* operationControllerVisitor) = 0;
private:
	shared_ptr<Game> game;
};

#endif /* OPERATIONCONTROLLER_H_ */
