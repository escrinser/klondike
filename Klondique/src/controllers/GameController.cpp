/*
 * GameController.cpp
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */
#include "GameController.h"

#include "../models/Game.h"
#include "../utils/LimitedInDialog.h"

#include "../views/KlondiqueView.h"


#define NUMBER_OF_CARDS 13
#define NUMBER_OF_PILES 7

GameController::~GameController() {
	// TODO Auto-generated destructor stub
}

void
GameController::control()
{
	cout << "GameController control" << endl;

	LimitedInDialog cardDialog ("Card Number?", 1, NUMBER_OF_CARDS);

	LimitedInDialog pileDialog ("Pile Number?", 1, NUMBER_OF_PILES);

	int movement;

	int pileNumberOrigin;
	int pileNumberDestination;
	int pileNumberOriginNumber = 0;

	LimitedInDialog mainMenuDialog ("Chose one option:\n\n"
			"1  Deal\n"
			"2  Move a card between Waste Pile to Pile\n"
			"3  Move a card between Piles\n"
			"4  Move a card between Pile to Foundation\n"
			"5  Move a card between Waste Pile to Foundation\n"
			"6  Exit\n"
			"Enter your choice and press return:", 1, 6);

	do
	{
		game->showBoard();
		movement = mainMenuDialog.read();
		switch (movement)
		{
		   case 1:
			   cout << "Deal a card"<<endl;
			   //Deal a card
			   game->deal();
			   break;

		   case 2:
			   cout << "Move a card between Waste Pile to Pile"<<endl;
			   game->moveBetweenWastePileAndPile(pileDialog.read());
			   break;

		   case 3:
		   {
			   cout << "Move card/cards between Piles"<<endl;
			   cout << "Origin Pile"<<endl;
			   pileNumberOrigin = pileDialog.read();

			   cout << "\nIs the last card? (yes/no)";
			   string lastCard;

			   cin >> lastCard;
			   if (lastCard == "no") //TODO: LimitedInDialog to string in the ClosedStringInterval.
			   {
				   cout << "\nPile Origin Card Number: ";
				   pileNumberOriginNumber = cardDialog.read();
			   }
			   else
			   {
				   pileNumberOriginNumber = 0;
			   }

			   cout << "Destination Pile"<<endl;
			   pileNumberDestination = pileDialog.read();
			   if (pileNumberOriginNumber != 0)
			   {
				   cout << "Pile Origin: " << pileNumberOrigin << " number: " << pileNumberOriginNumber <<" Pile Destination: " << pileNumberDestination  << endl;
			   }
			   else
			   {
				   cout << "Pile Origin: " << pileNumberOrigin << " Pile Destination: " << pileNumberDestination  << endl;
			   }

			   if (pileNumberOrigin == pileNumberDestination)
			   {
				   cout << "Impossible movement, the same pile. Pile Origin: " << pileNumberOrigin << " and Pile Destination: " << pileNumberDestination  << endl;
				   break;
			   }

			   game->moveBetweenPiles(pileNumberOrigin, pileNumberDestination, pileNumberOriginNumber);
			   break;
		   }
		   case 4:
		   {
			   cout << "Move a card between Pile and Foundation"<<endl;
			   game->moveBetweenPileAndFoundation(pileDialog.read());

			   break;
		   }
		   case 5:
		   {
			   cout << "Move a card between Waste Pile and Foundation"<<endl;
			   game->moveBetweenWastePileAndFoundation();
			   break;
		   }
		   case 6:
			   cout << "No more movements. Exit"<<endl;
			   break;

		   default:
			   cout << "Not a Valid Movement. Choose again.\n";
			   break;
		}
	}
	while ((movement != 6) && (!hasWon()));

	if (hasWon())
	{
		cout << "You win!!" << endl;
	}
	game->setState(State::FINAL);
}

void
GameController::accept(KlondiqueView* klondiqueView)
{
	klondiqueView->visit(this);
}
