/*
 * ClosedInterval.h
 *
 *  Created on: 5 nov. 2017
 *      Author: eseogaz
 */

#ifndef CLOSEDINTERVAL_H_
#define CLOSEDINTERVAL_H_

#include <iostream>

using namespace std;

class ClosedInterval {
public:
	ClosedInterval();
	ClosedInterval(int theMin, int theMax);
	virtual ~ClosedInterval();

	bool includes(int value);
	string toString();

private:
	int min;
	int max;
};

#endif /* CLOSEDINTERVAL_H_ */
