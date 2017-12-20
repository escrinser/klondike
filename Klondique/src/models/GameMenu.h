#ifndef MODELS_GAMEMENU_H_
#define MODELS_GAMEMENU_H_

#include "Menu.h"

class GameMenu : public Menu{
public:
	GameMenu(shared_ptr<Game> game);
	virtual ~GameMenu();
};

#endif /* MODELS_GAMEMENU_H_ */
