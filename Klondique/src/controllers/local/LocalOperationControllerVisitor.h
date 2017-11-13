/*
 * OperationControllerVisitor.h
 *
 *  Created on: 13 nov. 2017
 *      Author: Ana
 */

#ifndef CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_
#define CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_

class LocalStartController;
class LocalGameController;
class LocalContinueController;

class LocalOperationControllerVisitor {
public:
	LocalOperationControllerVisitor();
	virtual ~LocalOperationControllerVisitor();

	void virtual visit(LocalStartController* startController) = 0;
	void virtual visit(LocalGameController* gameController) = 0;
	void virtual visit(LocalContinueController* continueController) = 0;
};

#endif /* CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_ */
