/*
 * Pile.cpp
 *
 *  Created on: 10 oct. 2017
 *      Author: eseogaz
 */

#include "Pile.h"

Pile::Pile() {
	// TODO Auto-generated constructor stub

}

Pile::~Pile() {
	// TODO Auto-generated destructor stub
}

Pile::Pile(int theNumber, vector<CardInBoard> theCards)
{
	number = theNumber;
	cards = theCards;
}

void
Pile::print()
{

}

vector<CardInBoard>
Pile::getCards()
{
	return cards;
}

int
Pile::getNumber()
{
	return number;
}
