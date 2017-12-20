#ifndef KLONDIKE_H_
#define KLONDIKE_H_

#include "controllers/local/Logic.h"

#include "views/KlondiqueView.h"

#include "models/Menu.h"

class Klondike {
public:
	Klondike();
	virtual ~Klondike();

	void play();

    void exec();

private:
	Logic logic;

	KlondiqueView view;

	Menu* menu;
};

#endif /* KLONDIKE_H_ */
