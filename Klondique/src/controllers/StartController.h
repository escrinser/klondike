#ifndef CONTROLLERS_STARTCONTROLLER_H_
#define CONTROLLERS_STARTCONTROLLER_H_

#include "OperationController.h"

class StartController : public OperationController{
public:
	StartController() {};
	virtual ~StartController() {};
	virtual void setStart() = 0;
};

#endif /* CONTROLLERS_STARTCONTROLLER_H_ */
