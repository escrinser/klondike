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

shared_ptr<Suit>
Card::getSuit()
{
	return suit;
}

int
Card::getNumber()
{
	return number;
}
