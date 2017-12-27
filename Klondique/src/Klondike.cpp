#include "Klondike.h"

#include <iostream>

using namespace std;

Klondike::Klondike()
{
	menu = new Menu(shared_ptr<Game>(new Game()));
}

Klondike::~Klondike() {
}

void
Klondike::exec()
{
	view.interact(menu);
}

int main()
{
   cout << "The Sergio's Klondike." << endl;
   Klondike game;
   game.exec();
   return 0;
}


