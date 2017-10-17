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
}

Play::~Play() {
}


void
Play::startPlay()
{
	Deck deck;
	deck.loadDeck();

	vector<Card> initialDeck = deck.shuffle();

	// Pile1
	vector<CardInBoard> pile1;
	pile1.push_back(CardInBoard (initialDeck.back(), "upturned"));
	//cout << "Before Pile 1: " << initialDeck.size() << endl;
	initialDeck.pop_back();
	//cout << "After Pile 1: "<< initialDeck.size() << endl;

	// Pile2
	vector<CardInBoard> pile2;
	pile2.push_back(CardInBoard (initialDeck.back(), "downturned"));
	initialDeck.pop_back();
	pile2.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 2: "<< initialDeck.size() << endl;

	// Pile3
	vector<CardInBoard> pile3;
	for (int x=0; x<2; x++)
	{
		pile3.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile3.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 3: "<< initialDeck.size() << endl;

	// Pile4
	vector<CardInBoard> pile4;
	for (int x=0; x<3; x++)
	{
		pile4.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile4.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 4: "<< initialDeck.size() << endl;

	// Pile5
	vector<CardInBoard> pile5;
	for (int x=0; x<4; x++)
	{
		pile5.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile5.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 5: "<< initialDeck.size() << endl;

	// Pile6
	vector<CardInBoard> pile6;
	for (int x=0; x<5; x++)
	{
		pile6.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile6.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 6: "<< initialDeck.size() << endl;

	// Pile7
	vector<CardInBoard> pile7;
	for (int x=0; x<6; x++)
	{
		pile7.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile7.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 7: "<< initialDeck.size() << endl;

	Pile pileOne (1, pile1);
	Pile pileTwo (2, pile2);
	Pile pileThree (3, pile3);
	Pile pileFour (4, pile4);
	Pile pileFive (5, pile5);
	Pile pileSix (6, pile6);
	Pile pileSeven (7, pile7);

	vector<Pile> piles;
	piles.push_back(pileOne);
	piles.push_back(pileTwo);
	piles.push_back(pileThree);
	piles.push_back(pileFour);
	piles.push_back(pileFive);
	piles.push_back(pileSix);
	piles.push_back(pileSeven);


	//Foundations
	Suit suitHeart("heart", "red");
	Suit suitSpade("spade", "black");
	Suit suitClub("club", "black");
	Suit suitDiamond("diamond", "red");

	vector<CardInBoard> foundationHearts;
	Foundation foundationHeart (suitHeart, foundationHearts);

	vector<CardInBoard> foundationSpades;
	Foundation foundationSpade (suitSpade, foundationSpades);

	vector<CardInBoard> foundationClubs;
	Foundation foundationClub (suitClub, foundationClubs);

	vector<CardInBoard> foundationDiamonds;
	Foundation foundationDiamond (suitDiamond, foundationDiamonds);

	vector<Foundation> foundations;
	foundations.push_back(foundationHeart);
	foundations.push_back(foundationSpade);
	foundations.push_back(foundationClub);
	foundations.push_back(foundationDiamond);

	KlondiqueBoard boardSergio (deck, piles, foundations);
	//boardSergio.startPlayingBoard2();

	KlondiqueBoard board (deck);
	//board.initBoard();
	board.startPlayingBoard();
	//board.deal();

	int movement;
	int pileNumber;
	int foundationNumber; //TODO: Enter String with the suit, not numbers.

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
			   cout << "\nPile Destination: ";
			   cin >> pileNumber; //TODO: Number between 1-7
			   cout << "Movement from Waste Pile to Pile: " << pileNumber  << endl;
			   switch (pileNumber)
			   {
				   case 1:
					   board.moveBetweenWastePileAndPile(board.getWastePile(), board.getPile1());
					   break;
				   case 2:
					   board.moveBetweenWastePileAndPile(board.getWastePile(), board.getPile2());
					   break;
				   case 3:
					   board.moveBetweenWastePileAndPile(board.getWastePile(), board.getPile3());
					   break;
				   case 4:
					   board.moveBetweenWastePileAndPile(board.getWastePile(), board.getPile4());
					   break;
				   case 5:
					   board.moveBetweenWastePileAndPile(board.getWastePile(), board.getPile5());
					   break;
				   case 6:
					   board.moveBetweenWastePileAndPile(board.getWastePile(), board.getPile6());
					   break;
				   case 7:
					   board.moveBetweenWastePileAndPile(board.getWastePile(), board.getPile7());
					   break;
				   default:
					   cout << "Not a Valid Pile Number.\n";
					   break;
			   }
			   break;

		   case 3:
		   {
			   cout << "Move card/cards between Piles"<<endl;
			   cout << "\nPile Origin: ";
			   cin >> pileNumberOrigin;
			   cout << "\nPile Origin Card Number: ";
			   cin >> pileNumberOriginNumber;
			   cout << "\nPile Destination: ";
			   cin >> pileNumberDestination;
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

			   switch (pileNumberOrigin)
				{
					case 1:
					{
						switch (pileNumberDestination)
						{
							case 2:
							{
							   board.moveBetweenPiles(board.getPile1(), board.getPile2(), pileNumberOriginNumber);
							   break;
							}
							case 3:
							{
							   board.moveBetweenPiles(board.getPile1(), board.getPile3(), pileNumberOriginNumber);
							   break;
							}
							case 4:
							{
							   board.moveBetweenPiles(board.getPile1(), board.getPile4(), pileNumberOriginNumber);
							   break;
							}
							case 5:
							{
							   board.moveBetweenPiles(board.getPile1(), board.getPile5(), pileNumberOriginNumber);
							   break;
							}
							case 6:
							{
							   board.moveBetweenPiles(board.getPile1(), board.getPile6(), pileNumberOriginNumber);
							   break;
							}
							case 7:
							{
							   board.moveBetweenPiles(board.getPile1(), board.getPile7(), pileNumberOriginNumber);
							   break;
							}

							default:
								cout << "Not a Valid Piles Number.\n";
								break;
						}
						break;
					}
					case 2:
					{
						switch (pileNumberDestination)
						{
							case 1:
							{
							   board.moveBetweenPiles(board.getPile2(), board.getPile1(), pileNumberOriginNumber);
							   break;
							}
							case 3:
							{
							   board.moveBetweenPiles(board.getPile2(), board.getPile3(), pileNumberOriginNumber);
							   break;
							}
							case 4:
							{
							   board.moveBetweenPiles(board.getPile2(), board.getPile4(), pileNumberOriginNumber);
							   break;
							}
							case 5:
							{
							   board.moveBetweenPiles(board.getPile2(), board.getPile5(), pileNumberOriginNumber);
							   break;
							}
							case 6:
							{
							   board.moveBetweenPiles(board.getPile2(), board.getPile6(), pileNumberOriginNumber);
							   break;
							}
							case 7:
							{
							   board.moveBetweenPiles(board.getPile2(), board.getPile7(), pileNumberOriginNumber);
							   break;
							}

							default:
								cout << "Not a Valid Piles Number.\n";
								break;
						}
						break;
					}
					case 3:
					{
						switch (pileNumberDestination)
						{
							case 1:
							{
							   board.moveBetweenPiles(board.getPile3(), board.getPile1(), pileNumberOriginNumber);
							   break;
							}
							case 2:
							{
							   board.moveBetweenPiles(board.getPile3(), board.getPile2(), pileNumberOriginNumber);
							   break;
							}
							case 4:
							{
							   board.moveBetweenPiles(board.getPile3(), board.getPile4(), pileNumberOriginNumber);
							   break;
							}
							case 5:
							{
							   board.moveBetweenPiles(board.getPile3(), board.getPile5(), pileNumberOriginNumber);
							   break;
							}
							case 6:
							{
							   board.moveBetweenPiles(board.getPile3(), board.getPile6(), pileNumberOriginNumber);
							   break;
							}
							case 7:
							{
							   board.moveBetweenPiles(board.getPile3(), board.getPile7(), pileNumberOriginNumber);
							   break;
							}

							default:
								cout << "Not a Valid Piles Number.\n";
								break;
						}
						break;
					}
					case 4:
					{
						switch (pileNumberDestination)
						{
							case 1:
							{
							   board.moveBetweenPiles(board.getPile4(), board.getPile1(), pileNumberOriginNumber);
							   break;
							}
							case 2:
							{
							   board.moveBetweenPiles(board.getPile4(), board.getPile2(), pileNumberOriginNumber);
							   break;
							}
							case 3:
							{
							   board.moveBetweenPiles(board.getPile4(), board.getPile3(), pileNumberOriginNumber);
							   break;
							}
							case 5:
							{
							   board.moveBetweenPiles(board.getPile4(), board.getPile5(), pileNumberOriginNumber);
							   break;
							}
							case 6:
							{
							   board.moveBetweenPiles(board.getPile4(), board.getPile6(), pileNumberOriginNumber);
							   break;
							}
							case 7:
							{
							   board.moveBetweenPiles(board.getPile4(), board.getPile7(), pileNumberOriginNumber);
							   break;
							}

							default:
								cout << "Not a Valid Piles Number.\n";
								break;
						}
						break;
					}
					case 5:
					{
						switch (pileNumberDestination)
						{
							case 1:
							{
							   board.moveBetweenPiles(board.getPile5(), board.getPile1(), pileNumberOriginNumber);
							   break;
							}
							case 2:
							{
							   board.moveBetweenPiles(board.getPile5(), board.getPile2(), pileNumberOriginNumber);
							   break;
							}
							case 3:
							{
							   board.moveBetweenPiles(board.getPile5(), board.getPile3(), pileNumberOriginNumber);
							   break;
							}
							case 4:
							{
							   board.moveBetweenPiles(board.getPile5(), board.getPile4(), pileNumberOriginNumber);
							   break;
							}
							case 6:
							{
							   board.moveBetweenPiles(board.getPile5(), board.getPile6(), pileNumberOriginNumber);
							   break;
							}
							case 7:
							{
							   board.moveBetweenPiles(board.getPile5(), board.getPile7(), pileNumberOriginNumber);
							   break;
							}

							default:
								cout << "Not a Valid Piles Number.\n";
								break;
						}
						break;
					}
					case 6:
					{
						switch (pileNumberDestination)
						{
							case 1:
							{
							   board.moveBetweenPiles(board.getPile6(), board.getPile1(), pileNumberOriginNumber);
							   break;
							}
							case 2:
							{
							   board.moveBetweenPiles(board.getPile6(), board.getPile2(), pileNumberOriginNumber);
							   break;
							}
							case 3:
							{
							   board.moveBetweenPiles(board.getPile6(), board.getPile3(), pileNumberOriginNumber);
							   break;
							}
							case 4:
							{
							   board.moveBetweenPiles(board.getPile6(), board.getPile4(), pileNumberOriginNumber);
							   break;
							}
							case 5:
							{
							   board.moveBetweenPiles(board.getPile6(), board.getPile5(), pileNumberOriginNumber);
							   break;
							}
							case 7:
							{
							   board.moveBetweenPiles(board.getPile6(), board.getPile7(), pileNumberOriginNumber);
							   break;
							}

							default:
								cout << "Not a Valid Piles Number.\n";
								break;
						}
						break;
					}
					case 7:
					{
						switch (pileNumberDestination)
						{
							case 1:
							{
							   board.moveBetweenPiles(board.getPile7(), board.getPile1(), pileNumberOriginNumber);
							   break;
							}
							case 2:
							{
							   board.moveBetweenPiles(board.getPile7(), board.getPile2(), pileNumberOriginNumber);
							   break;
							}
							case 3:
							{
							   board.moveBetweenPiles(board.getPile7(), board.getPile3(), pileNumberOriginNumber);
							   break;
							}
							case 4:
							{
							   board.moveBetweenPiles(board.getPile7(), board.getPile4(), pileNumberOriginNumber);
							   break;
							}
							case 5:
							{
							   board.moveBetweenPiles(board.getPile7(), board.getPile5(), pileNumberOriginNumber);
							   break;
							}
							case 6:
							{
							   board.moveBetweenPiles(board.getPile7(), board.getPile6(), pileNumberOriginNumber);
							   break;
							}

							default:
								cout << "Not a Valid Piles Number.\n";
								break;
						}
						break;
					}

					default:
						cout << "Not a Valid Origin Pile Number.\n";
						break;
				}
			   break;
		   }
		   case 4:
		   {
			   cout << "Move a card between Pile and Foundation"<<endl;
			   cout << "\nPile Origin: ";
			   cin >> pileNumber;
			   cout << "Options: Heart= 1, Spade=2, Club=3, Diamond=4 "<<endl;
			   cout << "\nFoundation Destination: ";
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
					   board.moveBetweenPileAndFoundation(board.getPile1(), board.getFoundationHeart(), foundationNumber);
					   break;
				   case 12:
					   board.moveBetweenPileAndFoundation(board.getPile2(), board.getFoundationHeart(), foundationNumber);
					   break;
				   case 13:
					   board.moveBetweenPileAndFoundation(board.getPile3(), board.getFoundationHeart(), foundationNumber);
					   break;
				   case 14:
					   board.moveBetweenPileAndFoundation(board.getPile4(), board.getFoundationHeart(), foundationNumber);
					   break;
				   case 15:
					   board.moveBetweenPileAndFoundation(board.getPile5(), board.getFoundationHeart(), foundationNumber);
					   break;
				   case 16:
					   board.moveBetweenPileAndFoundation(board.getPile6(), board.getFoundationHeart(), foundationNumber);
					   break;
				   case 17:
					   board.moveBetweenPileAndFoundation(board.getPile7(), board.getFoundationHeart(), foundationNumber);
					   break;

				   case 21:
					   board.moveBetweenPileAndFoundation(board.getPile1(), board.getFoundationSpade(), foundationNumber);
					   break;
				   case 22:
					   board.moveBetweenPileAndFoundation(board.getPile2(), board.getFoundationSpade(), foundationNumber);
					   break;
				   case 23:
					   board.moveBetweenPileAndFoundation(board.getPile3(), board.getFoundationSpade(), foundationNumber);
					   break;
				   case 24:
					   board.moveBetweenPileAndFoundation(board.getPile4(), board.getFoundationSpade(), foundationNumber);
					   break;
				   case 25:
					   board.moveBetweenPileAndFoundation(board.getPile5(), board.getFoundationSpade(), foundationNumber);
					   break;
				   case 26:
					   board.moveBetweenPileAndFoundation(board.getPile6(), board.getFoundationSpade(), foundationNumber);
					   break;
				   case 27:
					   board.moveBetweenPileAndFoundation(board.getPile7(), board.getFoundationSpade(), foundationNumber);
					   break;

				   case 31:
					   board.moveBetweenPileAndFoundation(board.getPile1(), board.getFoundationClub(), foundationNumber);
					   break;
				   case 32:
					   board.moveBetweenPileAndFoundation(board.getPile2(), board.getFoundationClub(), foundationNumber);
					   break;
				   case 33:
					   board.moveBetweenPileAndFoundation(board.getPile3(), board.getFoundationClub(), foundationNumber);
					   break;
				   case 34:
					   board.moveBetweenPileAndFoundation(board.getPile4(), board.getFoundationClub(), foundationNumber);
					   break;
				   case 35:
					   board.moveBetweenPileAndFoundation(board.getPile5(), board.getFoundationClub(), foundationNumber);
					   break;
				   case 36:
					   board.moveBetweenPileAndFoundation(board.getPile6(), board.getFoundationClub(), foundationNumber);
					   break;
				   case 37:
					   board.moveBetweenPileAndFoundation(board.getPile7(), board.getFoundationClub(), foundationNumber);
					   break;

				   case 41:
					   board.moveBetweenPileAndFoundation(board.getPile1(), board.getFoundationDiamond(), foundationNumber);
					   break;
				   case 42:
					   board.moveBetweenPileAndFoundation(board.getPile2(), board.getFoundationDiamond(), foundationNumber);
					   break;
				   case 43:
					   board.moveBetweenPileAndFoundation(board.getPile3(), board.getFoundationDiamond(), foundationNumber);
					   break;
				   case 44:
					   board.moveBetweenPileAndFoundation(board.getPile4(), board.getFoundationDiamond(), foundationNumber);
					   break;
				   case 45:
					   board.moveBetweenPileAndFoundation(board.getPile5(), board.getFoundationDiamond(), foundationNumber);
					   break;
				   case 46:
					   board.moveBetweenPileAndFoundation(board.getPile6(), board.getFoundationDiamond(), foundationNumber);
					   break;
				   case 47:
					   board.moveBetweenPileAndFoundation(board.getPile7(), board.getFoundationDiamond(), foundationNumber);
					   break;

				   default:
					   cout << "Not a Valid Foundation Number.\n";
					   break;
			   }
			   break;
		   }
		   case 5:
		   {
			   do
			   {
				   cout << "Move a card between Waste Pile and Foundation"<<endl;
				   cout << "Options: Heart= 1, Spade=2, Club=3, Diamond=4 "<<endl;
				   cout << "\nFoundation Number: ";
			       cin >> foundationNumber; //TODO: Heart= 1, Spade=2, Club=3, Diamond=4
				   cout << "Foundation: " << foundationNumber  << endl;

				   switch (foundationNumber)
				   {
					   case 1:
						   board.moveBetweenWastePileAndFoundation(board.getWastePile(), board.getFoundationHeart(), foundationNumber);
						   break;
					   case 2:
						   board.moveBetweenWastePileAndFoundation(board.getWastePile(), board.getFoundationSpade(), foundationNumber);
						   break;
					   case 3:
						   board.moveBetweenWastePileAndFoundation(board.getWastePile(), board.getFoundationClub(), foundationNumber);
						   break;
					   case 4:
						   board.moveBetweenWastePileAndFoundation(board.getWastePile(), board.getFoundationDiamond(), foundationNumber);
						   break;

					   default:
						   cout << "Not a Valid Foundation Number. Choose again\n";
						   break;
				   }
			   } while (foundationNumber != 1 && foundationNumber != 2 && foundationNumber != 3 && foundationNumber != 1);
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
Play::hasWon(KlondiqueBoard theBoard)
{
	if (!theBoard.getFoundationHeart().empty()
			&& !theBoard.getFoundationSpade().empty()
				&& !theBoard.getFoundationClub().empty()
					&& !theBoard.getFoundationDiamond().empty())
	{
		if ((theBoard.getFoundationHeart().back().getCard().getNumber() == 13)
				&& (theBoard.getFoundationSpade().back().getCard().getNumber() == 13)
					 && (theBoard.getFoundationClub().back().getCard().getNumber() == 13)
						&& (theBoard.getFoundationDiamond().back().getCard().getNumber() == 13))
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
