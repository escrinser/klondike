/*
 * Foundation.cpp
 *
 *  Created on: 10 oct. 2017
 *      Author: eseogaz
 */

#include "Foundation.h"

Foundation::Foundation() {
}

Foundation::~Foundation() {
}


Foundation::Foundation(Suit theSuit, vector<CardInBoard> theCards)
{
	suit = theSuit;
	cards = theCards;
}

void
Foundation::print()
{

}

vector<CardInBoard>
Foundation::getCards()
{
	return cards;
}

Suit
Foundation::getSuit()
{
	return suit;
}
