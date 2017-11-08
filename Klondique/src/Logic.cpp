/*
 * Logic.cpp
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#include "Logic.h"

#include <iostream>

#include "Play.h"
#include "Game.h"
#include "StartController.h"
#include "MoveController.h"

using namespace std;

Logic::Logic() {
	game = shared_ptr<Game>(new Game());
	startController = shared_ptr<StartController>(new StartController(game));
    moveController = shared_ptr<MoveController>(new MoveController(game));
}

Logic::~Logic() {
	// TODO Auto-generated destructor stub
}

void
Logic::play()
{
	int choice;
	do
	{
	   cout << "Chose one option:\n\n";

	   cout << "1  Play\n";
	   cout << "2  End\n";
	   cout << "Enter your choice and press return: ";
	   cin >> choice;
	   Play start;
	   switch (choice)
	   {
		   case 1:
			   cout << "Start playing"<<endl;
			   start.startPlay();
			   break;

		   case 2:
			   cout << "End of the game."<<endl;
			   break;

		   default:
			   cout << "Not a Valid Choice. Choose again.\n";
			   break;
	   }
	}
	while (choice != 1 && choice != 2);
	/*OperationController controller;
	do {
		controller = logic.getController();
		if (controller != null){
			controller.control();
		}
	} while (controller != null);*/
}

/*OperationController getController() {
		switch (game.getState()){
		case INITIAL:
			return startController;
		case IN_GAME:
			return colocateControllerBuilder.getColocateController();
		case FINAL:
			return continueController;
		case EXIT:
		default:
			return null;
		}
}*/

