#include "LimitedInDialog.h"
#include "ClosedIntervalView.h"
#include "IO.h"

LimitedInDialog* LimitedInDialog::unique_instance = nullptr;

LimitedInDialog::LimitedInDialog(void)
{
}
LimitedInDialog::~LimitedInDialog(void)
{
}

/*LimitedInDialog::LimitedInDialog(string theTitle, int theMin, int theMax) {
	ClosedInterval closedInterval (theMin, theMax);
	limits = closedInterval;
	title = theTitle;

}

LimitedInDialog::~LimitedInDialog() {
}*/

int
LimitedInDialog::read(string title, int min, int max)
{
	ClosedInterval* limits = new ClosedInterval(min, max);
	ClosedIntervalView* limitsView = new ClosedIntervalView(
			"The value must be between ", limits);
	int value;
	bool ok;
	do {
		value = IO::getInstance()->readInt(title + " " + limitsView->toString() + ": ");
		ok = limits->includes(value);
		if (!ok) {
			limitsView->writeln();
		}
	} while (!ok);
	return value;
}


/*int
LimitedInDialog::read()
{
	int value;
	bool ok;
	do {
		cout << title;
		cin >> value;
		ok = limits.includes(value);
		if (!ok)
		{
			cout << "The value must be between the limits " + limits.toString() << endl;
		}
	} while (!ok);
	return value;
}*/

int
LimitedInDialog::read(string title, int max)
{
	return read(title, 1, max);
}
