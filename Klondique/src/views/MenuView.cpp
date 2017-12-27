#include <MenuView.h>

MenuView::MenuView() {


}

MenuView::~MenuView() {

}

void
MenuView::interact(Menu* menu)
{
   menu->execute();
}

