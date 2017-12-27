#ifndef KLONDIKE_H_
#define KLONDIKE_H_

#include "views/KlondiqueView.h"

#include "controllers/Menu.h"

class Klondike {
public:
	Klondike();
	virtual ~Klondike();

    void exec();

private:

	KlondiqueView view;

	Menu* menu;
};

#endif /* KLONDIKE_H_ */
