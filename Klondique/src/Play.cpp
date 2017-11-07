/*
 * Play.cpp
 *
 *  Created on: 9 oct. 2017
 *      Author: eseogaz
 */

#include "Play.h"

#include "Board.h"
#include "Deck.h"
#include "Card.h"
#include "CardInBoard.h"
#include "LimitedInDialog.h"

Play::Play() {
}

Play::~Play() {
}


void
Play::startPlay()
{
	LimitedInDialog cardDialog ("Card Number?", 1, 13);

	LimitedInDialog pileDialog ("Pile Number?", 1, 7);

	shared_ptr<Deck> deck (new Deck());
	deck->loadDeck();

	Board board (deck);
	//board.initBoard();
	board.startPlayingBoard();

	int movement;

	int pileNumberOrigin;
	int pileNumberDestination;
	int pileNumberOriginNumber = 0;

	do
	{
		board.showBoard();

		cout << "Chose one option:\n\n";

		cout << "1  Deal\n";
		cout << "2  Move a card between Waste Pile to Pile\n";
		cout << "3  Move a card between Piles\n";
		cout << "4  Move a card between Pile to Foundation\n";
		cout << "5  Move a card between Waste Pile to Foundation\n";
		cout << "22 Exit\n";
		cout << "Enter your choice and press return: ";
		cin >> movement;

		switch (movement)
		{
		   case 1:
			   cout << "Deal a card"<<endl;
			   //Deal a card
			   board.deal();
			   break;

		   case 2:
			   cout << "Move a card between Waste Pile to Pile"<<endl;
			   board.moveBetweenWastePileAndPile(pileDialog.read());
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

		       board.moveBetweenPiles(pileNumberOrigin, pileNumberDestination, pileNumberOriginNumber);
			   break;
		   }
		   case 4:
		   {
			   cout << "Move a card between Pile and Foundation"<<endl;
			   board.moveBetweenPileAndFoundation(pileDialog.read());

			   break;
		   }
		   case 5:
		   {
			   cout << "Move a card between Waste Pile and Foundation"<<endl;
			   board.moveBetweenWastePileAndFoundation();
			   break;
		   }
		   case 22:
			   cout << "No more movements. Exit"<<endl;
			   break;

		   default:
			   cout << "Not a Valid Movement. Choose again.\n";
			   break;
		}
	}
	while ((movement != 22) && (!hasWon(board)));
}


bool
Play::hasWon(Board theBoard)
{
	if (!theBoard.getFoundations()[0].empty()
			&& !theBoard.getFoundations()[1].empty()
				&& !theBoard.getFoundations()[2].empty()
					&& !theBoard.getFoundations()[3].empty())
	{
		if (((theBoard.getFoundations()[0].back()->getCard())->getNumber() == 13)
				&& (theBoard.getFoundations()[1].back()->getCard()->getNumber() == 13)
					 && (theBoard.getFoundations()[2].back()->getCard()->getNumber() == 13)
						&& (theBoard.getFoundations()[3].back()->getCard()->getNumber() == 13))
		{
			cout << "You win!!!" << endl;
			return true;
		}
		else
		{
			cout << "You are on the way to win, keep trying..." << endl;
			return false;
		}
	}
	else
	{
		cout << "You are on the way to win, keep trying..." << endl;
		return false;
	}
}
