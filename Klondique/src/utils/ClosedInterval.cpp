#include "ClosedInterval.h"

ClosedInterval::ClosedInterval() {
}
ClosedInterval::ClosedInterval(int theMin, int theMax) {
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

int
ClosedInterval::getMin()
{
	return min;
}

int
ClosedInterval::getMax() {
	return max;
}

