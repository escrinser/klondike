#include <ClosedIntervalView.h>
#include "IO.h"

ClosedIntervalView::~ClosedIntervalView() {
}

ClosedIntervalView::ClosedIntervalView(std::string theTitle, ClosedInterval* theClosedInterval)
{
	title = theTitle;
	closedInterval = theClosedInterval;
}

void
ClosedIntervalView::writeln()
{
	IO::getInstance()->writeln(title + " " + toString());
}

std::string
ClosedIntervalView::toString()
{
	return closedInterval->toString();
}

