/*
 * ContinueController.cpp
 *
 *  Created on: 10 nov. 2017
 *      Author: eseogaz
 */

#include "ContinueController.h"

#include "Game.h"
#include "LimitedInDialog.h"

ContinueController::~ContinueController() {
	// TODO Auto-generated destructor stub
}

void
ContinueController::control()
{
	//assert this.getState() == State.FINAL;
	cout << "ContinueController control" << endl;
	LimitedInDialog continueMenuDialog ("Chose one option:\n\n"
			"1  Continue\n"
			"2  Exit\n"
			"Enter your choice and press return:", 1, 2);
	int answer;
	do
	{
		answer = continueMenuDialog.read();
	}
	while (answer != 1 && answer != 2);

	if (answer == 1)
	{
		//this.clear(); //TODO: Reiniciar el juego...
		game->setState(State::INITIAL);
	}
	else
	{
		game->setState(State::EXIT);
	}
}


