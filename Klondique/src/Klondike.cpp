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
Klondike::play()
{
	shared_ptr<OperationController> controller;
	do {
		controller = logic.getController();
		if (controller != nullptr){
			view.interact(controller.get());
		}
	} while (controller != nullptr);
}

void
Klondike::exec()
{
	menu->execute();
}

int main()
{
   cout << "The First Version of Klondique." << endl;
   Klondike game;
   //game.play(); //Controllers...
   game.exec(); //Menus with Command
   return 0;
}


