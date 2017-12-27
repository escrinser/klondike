#ifndef VIEWS_KLONDIQUEVIEW_H_
#define VIEWS_KLONDIQUEVIEW_H_

#include <memory>

#include "../controllers/MenuVisitor.h"
#include "MenuView.h"
class Menu;

using namespace std;

class KlondiqueView : public MenuVisitor{
public:
	KlondiqueView();
	virtual ~KlondiqueView();

	void interact(Menu* menu);
	void visit(Menu* menu);

private:

	shared_ptr<MenuView> menuView;
};

#endif /* VIEWS_KLONDIQUEVIEW_H_ */
