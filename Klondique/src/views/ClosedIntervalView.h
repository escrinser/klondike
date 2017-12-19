#ifndef VIEWS_CLOSEDINTERVALVIEW_H_
#define VIEWS_CLOSEDINTERVALVIEW_H_

#include "ClosedInterval.h"

class ClosedIntervalView {
public:
	ClosedIntervalView(std::string title, ClosedInterval* closedInterval);
	virtual ~ClosedIntervalView();

	void writeln();

	std::string toString();

private:
	std::string title;

	ClosedInterval* closedInterval;
};

#endif /* VIEWS_CLOSEDINTERVALVIEW_H_ */
