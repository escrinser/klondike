#include <KlondiqueView.h>

#include "Menu.h"

KlondiqueView::KlondiqueView()
{
	menuView = shared_ptr<MenuView>(new MenuView());
}

KlondiqueView::~KlondiqueView() {
}

void
KlondiqueView::interact(Menu* menu)
{
		menu->accept(this);
}

void
KlondiqueView::visit(Menu* menu)
{
	menuView->interact(menu);
}
