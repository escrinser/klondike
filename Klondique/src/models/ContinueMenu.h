#ifndef MODELS_CONTINUEMENU_H_
#define MODELS_CONTINUEMENU_H_

#include "Menu.h"

class ContinueMenu : public Menu{
public:
	ContinueMenu(shared_ptr<Game> game);
	virtual ~ContinueMenu();
};

#endif /* MODELS_CONTINUEMENU_H_ */
