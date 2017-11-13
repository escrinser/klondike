/*
 * Controller.h
 *
 *  Created on: 13 nov. 2017
 *      Author: Ana
 */

#ifndef CONTROLLERS_CONTROLLER_H_
#define CONTROLLERS_CONTROLLER_H_

#include "../models/State.h"

class Controller {
public:
	Controller();
	virtual ~Controller();
	virtual void setState(State state) = 0;
	virtual void printBoard() = 0;
	virtual bool hasWon() = 0;
};

#endif /* CONTROLLERS_CONTROLLER_H_ */
