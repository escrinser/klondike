/*
 * OperationController.h
 *
 *  Created on: 13 nov. 2017
 *      Author: Ana
 */

#ifndef CONTROLLERS_OPERATIONCONTROLLER_H_
#define CONTROLLERS_OPERATIONCONTROLLER_H_

#include "Controller.h"

class OperationControllerVisitor;

class OperationController : public Controller{
public:
	OperationController() {};
	virtual ~OperationController() {};
	virtual void accept(OperationControllerVisitor* operationControllerVisitor) = 0;
};

#endif /* CONTROLLERS_OPERATIONCONTROLLER_H_ */
