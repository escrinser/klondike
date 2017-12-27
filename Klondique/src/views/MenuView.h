#ifndef VIEWS_MENUVIEW_H_
#define VIEWS_MENUVIEW_H_

#include "Menu.h"

class MenuView {
public:
	MenuView();
	virtual ~MenuView();
	void interact(Menu* menu);
};

#endif /* VIEWS_MENUVIEW_H_ */
