/*
 * Suit.cpp
 *
 *  Created on: 3 oct. 2017
 *      Author: Ana
 */

#include "Suit.h"

Suit::Suit() {
}

Suit::~Suit() {
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
