/*
 * Suit.cpp
 *
 *  Created on: 3 oct. 2017
 *      Author: Ana
 */

#include "Suit.h"

Suit::Suit() {
	// TODO Auto-generated constructor stub

}

Suit::~Suit() {
	// TODO Auto-generated destructor stub
}

Suit::Suit(string theSuit, string theColor)
{
	suit = theSuit;
	color = theColor;
}

string
Suit::getSuit()
{
	return suit;
}

string
Suit::getColor()
{
	return color;
}
