/*
 * Card.cpp
 *
 *  Created on: 3 oct. 2017
 *      Author: eseogaz
 */

#include "Card.h"


Card::Card() {
	// TODO Auto-generated constructor stub

}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

Card::Card(Suit theSuit, int theNumber)
{
	suit = theSuit;
	number = theNumber;
}

Suit
Card::getSuit()
{
	return suit;
}

int
Card::getNumber()
{
	return number;
}
