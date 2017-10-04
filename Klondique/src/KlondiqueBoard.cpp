/*
 * KlondiqueBoard.cpp
 *
 *  Created on: 3 oct. 2017
 *      Author: Ana
 */

#include "KlondiqueBoard.h"

KlondiqueBoard::KlondiqueBoard() {
	// TODO Auto-generated constructor stub

}

KlondiqueBoard::~KlondiqueBoard() {
	// TODO Auto-generated destructor stub
}


int
KlondiqueBoard::deal()
{
	return 0;
}

int
KlondiqueBoard::moveBetweenPiles()
{
	return 0;
}

int
KlondiqueBoard::moveBetweenPileAndFoundation()
{
	return 0;
}

int
KlondiqueBoard::moveBetweenDealAndPile()
{
	return 0;
}

vector<Card>
KlondiqueBoard::getPile1()
{
	return pile1;
}

vector<Card>
KlondiqueBoard::getPile2()
{
	return pile2;
}

vector<Card>
KlondiqueBoard::getPile3()
{
	return pile3;
}

vector<Card>
KlondiqueBoard::getPile4()
{
	return pile4;
}

vector<Card>
KlondiqueBoard::getPile5()
{
	return pile5;
}

vector<Card>
KlondiqueBoard::getPile6()
{
	return pile6;
}

vector<Card>
KlondiqueBoard::getPile7()
{
	return pile7;
}


vector<Card>
KlondiqueBoard::getFoundationHeart()
{
	return fountationHeart;
}

vector<Card>
KlondiqueBoard::getFoundationSpade()
{
	return fountationSpade;
}

vector<Card>
KlondiqueBoard::getFoundationClub()
{
	return fountationClub;
}

vector<Card>
KlondiqueBoard::getFoundationDiamond()
{
	return fountationDiamond;
}

void
KlondiqueBoard::showBoard()
{
	//Print all the Cards in the board (maximum 52)

	// 1) Downturned Deck
	for(vector<Card>::iterator it = downturnedDeck.getDeck().begin(); it != downturnedDeck.getDeck().end(); it++)
	{
	   cout << "Card in downturned Deck -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}

	// 2) Upturned Deck
	for(vector<Card>::iterator it = upturnedDeck.getDeck().begin(); it != upturnedDeck.getDeck().end(); it++)
	{
	   cout << "Card in upturned Deck -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}

	// 3) Foundation Heart (Only Hearts and in order from Ace to King)
	for(vector<Card>::iterator it = fountationHeart.begin(); it != fountationHeart.end(); it++)
	{
	   cout << "Card in foundation Heart -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}

	// 4) Foundation Spade (Only Spades and in order from Ace to King)
	for(vector<Card>::iterator it = fountationSpade.begin(); it != fountationSpade.end(); it++)
	{
	   cout << "Card in foundation Spade -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}

	// 5) Foundation Club (Only Clubs and in order from Ace to King)
	for(vector<Card>::iterator it = fountationClub.begin(); it != fountationClub.end(); it++)
	{
	   cout << "Card in foundation Club -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}

	// 6) Foundation Diamond (Only Diamonds and in order from Ace to King)
	for(vector<Card>::iterator it = fountationDiamond.begin(); it != fountationDiamond.end(); it++)
	{
	   cout << "Card in foundation Diamond -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}

	// 7) Pile 1 (maximum 13 Cards, no downturned)
	for(vector<Card>::iterator it = pile1.begin(); it != pile1.end(); it++)
	{
	   cout << "Card in Pile 1 -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}

	// 8) Pile 2 (maximum 14 Cards, 1 possible downturned)
	for(vector<Card>::iterator it = pile2.begin(); it != pile2.end(); it++)
	{
	   cout << "Card in Pile 2 -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}

	// 9) Pile 3 (maximum 15 Cards, 2 possible downturned)
	for(vector<Card>::iterator it = pile3.begin(); it != pile3.end(); it++)
	{
	   cout << "Card in Pile 3 -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}

	// 10) Pile 4 (maximum 16 Cards, 3 possible downturned)
	for(vector<Card>::iterator it = pile4.begin(); it != pile4.end(); it++)
	{
	   cout << "Card in Pile 4 -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}

	// 11) Pile 5 (maximum 17 Cards, 4 possible downturned)
	for(vector<Card>::iterator it = pile5.begin(); it != pile5.end(); it++)
	{
	   cout << "Card in Pile 5 -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}

	// 12) Pile 6 (maximum 18 Cards, 5 possible downturned)
	for(vector<Card>::iterator it = pile6.begin(); it != pile6.end(); it++)
	{
	   cout << "Card in Pile 6 -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}

	// 13) Pile 7 (maximum 19 Cards, 6 possible downturned)
	for(vector<Card>::iterator it = pile7.begin(); it != pile7.end(); it++)
	{
	   cout << "Card in Pile 7 -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
	}
}


void
KlondiqueBoard::upturnCardInPile()
{

}
