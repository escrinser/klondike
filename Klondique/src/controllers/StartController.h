/*
 * StartController.h
 *
 *  Created on: 13 nov. 2017
 *      Author: Ana
 */

#ifndef CONTROLLERS_STARTCONTROLLER_H_
#define CONTROLLERS_STARTCONTROLLER_H_

#include "OperationController.h"

#include "State.h"

class StartController : public OperationController{
public:
	StartController();
	virtual ~StartController();
	virtual void setStart(State theState) = 0;
};

#endif /* CONTROLLERS_STARTCONTROLLER_H_ */
