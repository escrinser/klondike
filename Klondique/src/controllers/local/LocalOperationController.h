#ifndef LOCALOPERATIONCONTROLLER_H_
#define LOCALOPERATIONCONTROLLER_H_

#include <memory>

#include "OperationControllerVisitor.h"
#include "LocalController.h"
#include "OperationController.h"

class Game;

using namespace std;

class LocalOperationController : public OperationController, LocalController {
public:
	LocalOperationController(shared_ptr<Game> theGame): LocalController(theGame){};
	virtual ~LocalOperationController();
	virtual void accept(OperationControllerVisitor* operationControllerVisitor) = 0;
};

#endif /* LOCALOPERATIONCONTROLLER_H_ */
