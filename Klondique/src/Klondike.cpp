/*
 * Klondike.cpp
 *
 *  Created on: 13 nov. 2017
 *      Author: eseogaz
 */

#include "Klondike.h"
#include "controllers/local/LocalOperationController.h"

#include <iostream>

using namespace std;

Klondike::Klondike()
{
}

Klondike::~Klondike() {
	// TODO Auto-generated destructor stub
}


void
Klondike::play()
{
	shared_ptr<OperationController> controller;
	//shared_ptr<LocalOperationController> controller;
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


