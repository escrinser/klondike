#include "Suit.h"

Suit::~Suit() {
}

Suit::Suit(SuitType theSuit, SuitColor theColour, int theNumberOfCards)
{
	suit = theSuit;
	color = theColour;
	numberOfCards = theNumberOfCards;
}

SuitType
Suit::getSuit()
{
	return suit;
}

string
Suit::toString(SuitType suitType)
{
	switch(suitType)
	{
	    case SuitType::HEART  :
	    	return "heart_R";
	    	break;
	    case SuitType::CLUB  :
	    	return "club_B";
	    	break;
	    case SuitType::SPADE  :
	    	return "spade_B";
	    	break;
	    case SuitType::DIAMOND  :
	    	return "diamond_R";
	    	break;
	}
	return "";
}

SuitColor
Suit::getColor()
{
	return color;
}

int
Suit::getNumberOfCards()
{
	return numberOfCards;
}
