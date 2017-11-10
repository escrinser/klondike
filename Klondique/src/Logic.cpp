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
#include "OperationController.h"
#include "StartController.h"
#include "MoveController.h"
#include "ContinueController.h"
#include "LimitedInDialog.h"


using namespace std;

Logic::Logic() {
	game = shared_ptr<Game>(new Game());
	startController = shared_ptr<StartController>(new StartController(game));
    moveController = shared_ptr<MoveController>(new MoveController(game));
    continueController = shared_ptr<ContinueController>(new ContinueController(game));
}

Logic::~Logic() {
	// TODO Auto-generated destructor stub
}

void
Logic::play()
{
	/*LimitedInDialog mainMenuDialog ("Chose one option:\n\n1  Play\n2  End\nEnter your choice and press return:", 1, 2);
	int choice;
	do
	{
	   choice = mainMenuDialog.read();
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
	while (choice != 1 && choice != 2);*/

	shared_ptr<OperationController> controller;
	do {
		controller = getController();
		if (controller != nullptr)
		{
			controller->control();
		}
	} while (controller != nullptr);
}

shared_ptr<OperationController>
Logic::getController()
{
		switch (game->getState())
		{
			case INITIAL:
				return startController;
			case IN_GAME:
				return moveController; //TODO: PlayController?
			case FINAL:
				return continueController;
			case EXIT:
			default:
				return nullptr;
		}
}

