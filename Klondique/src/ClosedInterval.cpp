/*
 * ClosedInterval.cpp
 *
 *  Created on: 5 nov. 2017
 *      Author: eseogaz
 */

#include "ClosedInterval.h"

#include <assert.h>     /* assert */

ClosedInterval::ClosedInterval() {
}
ClosedInterval::ClosedInterval(int theMin, int theMax) {
	assert (min <= max);
	min = theMin;
	max = theMax;
}

ClosedInterval::~ClosedInterval() {
	// TODO Auto-generated destructor stub
}

bool
ClosedInterval::includes(int theValue)
{
	return min <= theValue && theValue<= max;
}

string
ClosedInterval::toString() {
	return "[" + to_string(min) + ", " + to_string(max) + "]";
}

