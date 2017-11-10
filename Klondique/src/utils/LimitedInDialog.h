/*
 * LimitedInDialog.h
 *
 *  Created on: 5 nov. 2017
 *      Author: eseogaz
 */

#ifndef LIMITEDINDIALOG_H_
#define LIMITEDINDIALOG_H_

#include <iostream>

#include "ClosedInterval.h"

using namespace std;

class LimitedInDialog {
public:
	LimitedInDialog(string title, int min, int max);

	virtual ~LimitedInDialog();

	int read();

private:
	ClosedInterval limits;
	string title;
};

#endif /* LIMITEDINDIALOG_H_ */
