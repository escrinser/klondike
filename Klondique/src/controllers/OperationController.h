/*
 * OperationController.h
 *
 *  Created on: 13 nov. 2017
 *      Author: Ana
 */

#ifndef CONTROLLERS_OPERATIONCONTROLLER_H_
#define CONTROLLERS_OPERATIONCONTROLLER_H_

class OperationControllerVisitor;

class OperationController{
public:
	OperationController() {};
	virtual ~OperationController() {};
	virtual void accept(OperationControllerVisitor* operationControllerVisitor) = 0;
};

#endif /* CONTROLLERS_OPERATIONCONTROLLER_H_ */
