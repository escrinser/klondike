/*
 * Card.cpp
 *
 *  Created on: 3 oct. 2017
 *      Author: eseogaz
 */

#include "Card.h"

Card::Card() {
}

Card::~Card() {
}

Card::Card(shared_ptr<Suit> theSuit, int theNumber)
{
	suit = theSuit;
	number = theNumber;
}

/*Card::Card(shared_ptr<Suit> theSuit, CardType theCardType)
{
	suit = theSuit;
	cardType = theCardType;
}*/

shared_ptr<Suit>
Card::getSuit()
{
	return suit;
}

/*CardType
Card::getType()
{
	return cardType;
}*/

int
Card::getNumber()
{
	return number;
}
