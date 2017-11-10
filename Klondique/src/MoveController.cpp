/*
 * MoveController.cpp
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#include "MoveController.h"

#include "Game.h"
#include "LimitedInDialog.h"

#include "Play.h"


MoveController::~MoveController() {
	// TODO Auto-generated destructor stub
}

void
MoveController::control()
{
	/*this.colocate();
	this.write();
	if (this.existTicTacToe()) {
		io.writeln("Victoria!!!! " + this.take() + "! " + this.take()
				+ "! " + this.take() + "! Victoria!!!!");
		this.setState(State.FINAL);
	} else {
		this.change();
	}*/
	cout << "MoveController control" << endl;
	LimitedInDialog mainMenuDialog ("Chose one option:\n\n1  Play\n2  End\nEnter your choice and press return:", 1, 2);
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
			   game->setState(State::FINAL);
			   break;

		   default:
			   cout << "Not a Valid Choice. Choose again.\n";
			   break;
	   }
	}
	while (choice != 1 && choice != 2);
}
