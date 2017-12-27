#ifndef CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_
#define CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_

class StartController;
class GameController;
class ContinueController;


class OperationControllerVisitor {
public:
	OperationControllerVisitor() {};
	virtual ~OperationControllerVisitor() {};
	void virtual visit(StartController* startController) = 0;
	void virtual visit(GameController* gameController) = 0;
	void virtual visit(ContinueController* continueController) = 0;
};

#endif /* CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_ */
