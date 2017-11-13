/*
 * ContinueController.cpp
 *
 *  Created on: 10 nov. 2017
 *      Author: eseogaz
 */

#include "ContinueController.h"

#include "../models/Game.h"
#include "../utils/LimitedInDialog.h"

#include "../views/KlondiqueView.h"

ContinueController::~ContinueController() {
	// TODO Auto-generated destructor stub
}

void
ContinueController::control()
{
	cout << "ContinueController control" << endl;
	LimitedInDialog continueMenuDialog ("Chose one option:\n\n"
			"1  Play again\n"
			"2  Continue\n"
			"3  Exit\n"
			"Enter your choice and press return:", 1, 3);
	int answer;
	do
	{
		answer = continueMenuDialog.read();
	}
	while (answer != 1 && answer != 2 && answer != 3);

	if (answer == 1)
	{
		game->clear();
		game->showBoard();
		game->setState(State::INITIAL);
	}
	else if (answer == 2)
	{
		game->setState(State::IN_GAME);
	}
	else
	{
		game->setState(State::EXIT);
	}
}

void
ContinueController::accept(KlondiqueView* klondiqueView)
{
	klondiqueView->visit(this);
}


