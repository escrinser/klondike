#ifndef CONTROLLERS_CONTINUECONTROLLER_H_
#define CONTROLLERS_CONTINUECONTROLLER_H_

#include "OperationController.h"

class ContinueController : public OperationController{
public:
	ContinueController() {};
	virtual ~ContinueController() {};
	virtual void setContinue(int theOption) = 0;
	virtual void clear() = 0;
};

#endif /* CONTROLLERS_CONTINUECONTROLLER_H_ */
