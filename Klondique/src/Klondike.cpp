#include "Klondike.h"

#include <iostream>

using namespace std;

Klondike::Klondike()
{
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

int main()
{
   cout << "The First Version of Klondique." << endl;
   Klondike game;
   game.play();

   return 0;
}


