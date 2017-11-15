#ifndef KLONDIKE_H_
#define KLONDIKE_H_

#include "controllers/local/Logic.h"

#include "views/KlondiqueView.h"

class Klondike {
public:
	Klondike();
	virtual ~Klondike();

	void play();

private:
	Logic logic;

	KlondiqueView view;
};

#endif /* KLONDIKE_H_ */
