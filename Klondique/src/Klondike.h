/*
 * Klondike.h
 *
 *  Created on: 13 nov. 2017
 *      Author: eseogaz
 */

#ifndef KLONDIKE_H_
#define KLONDIKE_H_

#include "controllers/Logic.h"
#include "controllers/OperationController.h"

#include "views/KlondiqueView.h"

class Klondike {
public:
	Klondike();
	virtual ~Klondike();

	void play();

private:
	Logic logic;

	KlondiqueView view;
};

#endif /* KLONDIKE_H_ */
