/*
 * ClosedIntervalView.cpp
 *
 *  Created on: 19 dic. 2017
 *      Author: eseogaz
 */

#include <ClosedIntervalView.h>
#include "IO.h"

ClosedIntervalView::~ClosedIntervalView() {
	// TODO Auto-generated destructor stub
}

ClosedIntervalView::ClosedIntervalView(std::string theTitle, ClosedInterval* theClosedInterval)
{
	title = theTitle;
	closedInterval = theClosedInterval;
}

void
ClosedIntervalView::writeln()
{
	//cout << title << " " << toString() <<endl;
	IO::getInstance()->writeln(title + " " + toString());
}

std::string
ClosedIntervalView::toString()
{
	return closedInterval->toString();
	//return "[" + closedInterval->getMin() + ", " + closedInterval->getMax() + "]";
}

