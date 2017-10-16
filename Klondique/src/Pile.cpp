/*
 * Pile.cpp
 *
 *  Created on: 10 oct. 2017
 *      Author: eseogaz
 */

#include "Pile.h"

Pile::Pile() {
}

Pile::~Pile() {
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
