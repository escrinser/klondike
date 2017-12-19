#ifndef LIMITEDINDIALOG_H_
#define LIMITEDINDIALOG_H_

#include <iostream>

#include "ClosedInterval.h"

using namespace std;

/*class LimitedInDialog {
public:

	LimitedInDialog(string title, int min, int max);

	virtual ~LimitedInDialog();

	int read();

private:
	ClosedInterval limits;
	string title;
};*/

class LimitedInDialog
{
private:
	LimitedInDialog(void);
	static LimitedInDialog* unique_instance;

public:
	~LimitedInDialog(void);

	static LimitedInDialog* getInstance()
	{
		if(unique_instance == nullptr)
		{
			unique_instance = new LimitedInDialog();
		}
		return unique_instance;
	}

	int read(string title, int min, int max);

	int read(string title, int max);
};

#endif /* LIMITEDINDIALOG_H_ */
