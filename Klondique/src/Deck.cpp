/*
 * Deck.cpp
 *
 *  Created on: 3 oct. 2017
 *      Author: eseogaz
 */

#include "Deck.h"

Deck::Deck() {
	// TODO Auto-generated constructor stub

}

Deck::~Deck() {
	// TODO Auto-generated destructor stub
}

vector<Card>
Deck::loadDeck()
{
	for (int suit; suit < 4; suit++)
	{
		for (int i; i < 12 ; i++)
		{
			cout << "Adding a card: number" << i+1 << " heart with color red" << endl;
		}
	}

	cout << "The First Version of the Deck." << endl;

	//Card
	vector<Card> theInitialDeck;
	//theInitialDeck.insert()
    //TODO: shuffle the deck
	return theInitialDeck;
}


vector<Card>
Deck::shuffle(vector<Card> theInitialDeck)
{
	vector<Card> theFinalDeck = theInitialDeck;
    //TODO: shuffle the deck
	return theFinalDeck;
}
