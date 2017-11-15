#include "LimitedInDialog.h"

#include <assert.h>

LimitedInDialog::LimitedInDialog(string theTitle, int theMin, int theMax) {
	//assert (!theTitle.empty());
	ClosedInterval closedInterval (theMin, theMax);
	limits = closedInterval;
	title = theTitle;

}

LimitedInDialog::~LimitedInDialog() {
}

int
LimitedInDialog::read(){
		int value;
		bool ok;
		do {
			cout << title;
			cin >> value;
			ok = limits.includes(value);
			if (!ok)
			{
				cout << "El valor debe estar entre los límites " + limits.toString() << endl;
			}
		} while (!ok);
		return value;
}
