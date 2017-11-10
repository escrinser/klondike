/*
 * StartController.cpp
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#include "StartController.h"

#include "Game.h"
#include "LimitedInDialog.h"

StartController::~StartController() {
	// TODO Auto-generated destructor stub
}

void
StartController::control()
{
	cout << "StartController control" << endl;
	game->startPlayingBoard();

	LimitedInDialog startDialog ("Chose one option:\n\n"
			"1  Play\n"
			"2  Exit\n"
			"Enter your choice and press return:", 1, 2);
	int choice;
	do
	{
	   choice = startDialog.read();
	   switch (choice)
	   {
		   case 1:
			   cout << "Start playing"<<endl;
			   game->setState(State::IN_GAME);
			   break;

		   case 2:
			   cout << "Exit."<<endl;
			   game->setState(State::FINAL);
			   break;

		   default:
			   cout << "Not a Valid Choice. Choose again.\n";
			   break;
	   }
	}
	while (choice != 1 && choice != 2);
}

