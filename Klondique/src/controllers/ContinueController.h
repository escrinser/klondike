/*
 * ContinueController.h
 *
 *  Created on: 13 nov. 2017
 *      Author: Ana
 */

#ifndef CONTROLLERS_CONTINUECONTROLLER_H_
#define CONTROLLERS_CONTINUECONTROLLER_H_

#include "OperationController.h"

class ContinueController : public OperationController{
public:
	ContinueController();
	virtual ~ContinueController();
	virtual void setContinue(int theOption) = 0;
};

#endif /* CONTROLLERS_CONTINUECONTROLLER_H_ */
