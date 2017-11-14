/*
 * KlondiqueView.cpp
 *
 *  Created on: 13 nov. 2017
 *      Author: eseogaz
 */

#include <KlondiqueView.h>

#include "../controllers/OperationController.h"
#include "../controllers/StartController.h"
#include "../controllers/GameController.h"
#include "../controllers/ContinueController.h"

#include "../utils/LimitedInDialog.h"

#include "BoardView.h"

#define NUMBER_OF_CARDS 13
#define NUMBER_OF_PILES 7

KlondiqueView::KlondiqueView() {
	// TODO Auto-generated constructor stub

}

KlondiqueView::~KlondiqueView() {
	// TODO Auto-generated destructor stub
}

void
KlondiqueView::interact(OperationController* controller)
{
		//assert controller != null;
		controller->accept(this);
}

void
KlondiqueView::visit(StartController* startController)
{
	LimitedInDialog startDialog ("Chose one option:\n\n"
			"1  Play\n"
			"2  Exit\n"
			"Enter your choice and press return:", 1, 2);
	int choice = startDialog.read();
	switch (choice)
	{
	   case 1:
		   cout << "Start playing"<<endl;
		   startController->setStart(State::IN_GAME);
		   break;

	   case 2:
		   cout << "Exit."<<endl;
		   startController->setStart(State::FINAL);
		   break;

	   default:
		   cout << "Not a Valid Choice. Choose again.\n";
		   break;
	}
	BoardView(startController).showBoard();
}

void
KlondiqueView::visit(GameController* gameController)
{
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
		BoardView(gameController).showBoard();
		movement = mainMenuDialog.read();
		switch (movement)
		{
		   case 1:
			   cout << "Deal a card"<<endl;
			   //Deal a card
			   gameController->deal();
			   break;

		   case 2:
			   cout << "Move a card between Waste Pile to Pile"<<endl;
			   gameController->moveBetweenWastePileAndPile(pileDialog.read());
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

			   gameController->moveBetweenPiles(pileNumberOrigin, pileNumberDestination, pileNumberOriginNumber);
			   break;
		   }
		   case 4:
		   {
			   cout << "Move a card between Pile and Foundation"<<endl;
			   gameController->moveBetweenPileAndFoundation(pileDialog.read());

			   break;
		   }
		   case 5:
		   {
			   cout << "Move a card between Waste Pile and Foundation"<<endl;
			   gameController->moveBetweenWastePileAndFoundation();
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
	while ((movement != 6) && (!gameController->hasWon()));

	if (gameController->hasWon())
	{
		cout << "You win!!" << endl;
	}
	//gameController->setState(State::FINAL);
}

void
KlondiqueView::visit(ContinueController* continueController)
{
	LimitedInDialog continueMenuDialog ("Chose one option:\n\n"
			"1  Play again\n"
			"2  Continue\n"
			"3  Exit\n"
			"Enter your choice and press return:", 1, 3);

	continueController->setContinue(continueMenuDialog.read());
}

