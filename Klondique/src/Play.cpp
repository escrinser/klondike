/*
 * Play.cpp
 *
 *  Created on: 9 oct. 2017
 *      Author: eseogaz
 */

#include "Play.h"

#include "Deck.h"
#include "KlondiqueBoard.h"

Play::Play() {
	// TODO Auto-generated constructor stub

}

Play::~Play() {
	// TODO Auto-generated destructor stub
}


void
Play::startPlay()
{
	Deck deck;
	deck.loadDeck();

	KlondiqueBoard board (deck);
	//board.initBoard();
	board.startPlayingBoard();
	//board.deal();

	int movement;
	int pileNumber;
	int foundationNumber; //TODO: Enter String with the suit, not numbers.

	cout << "The First Movement." << endl;
	do
	{
		cout << "Chose one option:\n\n";

		cout << "1  Deal\n";
		cout << "2  Move a card between upturned to Pile\n";
		cout << "3  Move a card between Piles\n";
		cout << "4  Move a card between Pile to Foundation\n";
		cout << "5  Move a card between upturned to Foundation\n";
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
			   cout << "Move a card between upturned to Pile"<<endl;
			   cin >> pileNumber; //TODO: Number between 1-7
			   //First movement (upturned to Pile1)
			   cout << "First movement from upturned to Pile: " << pileNumber  << endl;
			   switch (pileNumber)
			   {
				   case 1:
					   board.moveBetweenDealAndPile(board.getUpturnedDeck(), board.getPile1());
					   break;
				   case 2:
					   board.moveBetweenDealAndPile(board.getUpturnedDeck(), board.getPile2());
					   break;
				   case 3:
					   board.moveBetweenDealAndPile(board.getUpturnedDeck(), board.getPile3());
					   break;
				   case 4:
					   board.moveBetweenDealAndPile(board.getUpturnedDeck(), board.getPile4());
					   break;
				   case 5:
					   board.moveBetweenDealAndPile(board.getUpturnedDeck(), board.getPile5());
					   break;
				   case 6:
					   board.moveBetweenDealAndPile(board.getUpturnedDeck(), board.getPile6());
					   break;
				   case 7:
					   board.moveBetweenDealAndPile(board.getUpturnedDeck(), board.getPile7());
					   break;
				   default:
					   cout << "Not a Valid Pile Number.\n";
					   break;
			   }
			   break;

		   case 3:
			   cout << "Move a card between Piles"<<endl;
			   //Second movement (Pile7 to Pile2)
			   cout << "Second movement (Pile7 to Pile2)" << endl;
			   board.moveBetweenPiles(board.getPile7(), board.getPile2());
			   break;

		   case 4:
		   {
			   cout << "Move a card between Pile and Foundation"<<endl;

			   cin >> pileNumber;
			   cin >> foundationNumber;
			   cout << "Pile: " << pileNumber << " Foundation: " << foundationNumber  << endl;

			   //Foundation heart      x10 (11 from Pile 1 to Foundation Hearts)
			   //Foundation spade      x20 (21 from Pile 1 to Foundation Spades)
			   //Foundation club       x30 (31 from Pile 1 to Foundation Clubs)
			   //Foundation diamond    x40 (41 from Pile 1 to Foundation Diamonds)
			   int suma = (foundationNumber*10) + pileNumber;

			   switch (suma)
			   {
				   case 11:
					   board.moveBetweenPileAndFoundation(board.getPile1(), board.getFoundationHeart());
					   break;
				   case 12:
					   board.moveBetweenPileAndFoundation(board.getPile2(), board.getFoundationHeart());
					   break;
				   case 13:
					   board.moveBetweenPileAndFoundation(board.getPile3(), board.getFoundationHeart());
					   break;
				   case 14:
					   board.moveBetweenPileAndFoundation(board.getPile4(), board.getFoundationHeart());
					   break;
				   case 15:
					   board.moveBetweenPileAndFoundation(board.getPile5(), board.getFoundationHeart());
					   break;
				   case 16:
					   board.moveBetweenPileAndFoundation(board.getPile6(), board.getFoundationHeart());
					   break;
				   case 17:
					   board.moveBetweenPileAndFoundation(board.getPile7(), board.getFoundationHeart());
					   break;

				   case 21:
					   board.moveBetweenPileAndFoundation(board.getPile1(), board.getFoundationSpade());
					   break;
				   case 22:
					   board.moveBetweenPileAndFoundation(board.getPile2(), board.getFoundationSpade());
					   break;
				   case 23:
					   board.moveBetweenPileAndFoundation(board.getPile3(), board.getFoundationSpade());
					   break;
				   case 24:
					   board.moveBetweenPileAndFoundation(board.getPile4(), board.getFoundationSpade());
					   break;
				   case 25:
					   board.moveBetweenPileAndFoundation(board.getPile5(), board.getFoundationSpade());
					   break;
				   case 26:
					   board.moveBetweenPileAndFoundation(board.getPile6(), board.getFoundationSpade());
					   break;
				   case 27:
					   board.moveBetweenPileAndFoundation(board.getPile7(), board.getFoundationSpade());
					   break;

				   case 31:
					   board.moveBetweenPileAndFoundation(board.getPile1(), board.getFoundationClub());
					   break;
				   case 32:
					   board.moveBetweenPileAndFoundation(board.getPile2(), board.getFoundationClub());
					   break;
				   case 33:
					   board.moveBetweenPileAndFoundation(board.getPile3(), board.getFoundationClub());
					   break;
				   case 34:
					   board.moveBetweenPileAndFoundation(board.getPile4(), board.getFoundationClub());
					   break;
				   case 35:
					   board.moveBetweenPileAndFoundation(board.getPile5(), board.getFoundationClub());
					   break;
				   case 36:
					   board.moveBetweenPileAndFoundation(board.getPile6(), board.getFoundationClub());
					   break;
				   case 37:
					   board.moveBetweenPileAndFoundation(board.getPile7(), board.getFoundationClub());
					   break;

				   case 41:
					   board.moveBetweenPileAndFoundation(board.getPile1(), board.getFoundationDiamond());
					   break;
				   case 42:
					   board.moveBetweenPileAndFoundation(board.getPile2(), board.getFoundationDiamond());
					   break;
				   case 43:
					   board.moveBetweenPileAndFoundation(board.getPile3(), board.getFoundationDiamond());
					   break;
				   case 44:
					   board.moveBetweenPileAndFoundation(board.getPile4(), board.getFoundationDiamond());
					   break;
				   case 45:
					   board.moveBetweenPileAndFoundation(board.getPile5(), board.getFoundationDiamond());
					   break;
				   case 46:
					   board.moveBetweenPileAndFoundation(board.getPile6(), board.getFoundationDiamond());
					   break;
				   case 47:
					   board.moveBetweenPileAndFoundation(board.getPile7(), board.getFoundationDiamond());
					   break;

				   default:
					   cout << "Not a Valid Foundation Number.\n";
					   break;
			   }
			   break;
		   }
		   case 5:
		   {
			   cout << "Move a card between upturned and Foundation"<<endl;
			   cout << "Options: Heart= 1, Spade=2, Club=3, Diamond=4 "<<endl;
			   cin >> foundationNumber; //TODO: Heart= 1, Spade=2, Club=3, Diamond=4
			   cout << "Foundation: " << foundationNumber  << endl;

			   switch (foundationNumber)
			   {
				   case 1:
					   board.moveBetweenDealAndFoundation(board.getUpturnedDeck(), board.getFoundationHeart());
					   break;
				   case 2:
					   board.moveBetweenDealAndFoundation(board.getUpturnedDeck(), board.getFoundationSpade());
					   break;
				   case 3:
					   board.moveBetweenDealAndFoundation(board.getUpturnedDeck(), board.getFoundationClub());
					   break;
				   case 4:
					   board.moveBetweenDealAndFoundation(board.getUpturnedDeck(), board.getFoundationDiamond());
					   break;

				   default:
					   cout << "Not a Valid Foundation Number.\n";
					   break;
			   }
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
	while (movement != 22);
}

//TODO: Upturn one card
//



