#include "ClosedInterval.h"

#include <assert.h>     /* assert */

ClosedInterval::ClosedInterval() {
}
ClosedInterval::ClosedInterval(int theMin, int theMax) {
	//assert (min <= max);
	min = theMin;
	max = theMax;
}

ClosedInterval::~ClosedInterval() {
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

