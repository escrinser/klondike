#include "Suit.h"
Suit::Suit() {
}

Suit::~Suit() {
}

Suit::Suit(Suit::SuitType theSuit, Suit::SuitColor theColour, int theNumberOfCards)
{
	suit = theSuit;
	color = theColour;
	numberOfCards = theNumberOfCards;
}

Suit::SuitType
Suit::getSuit()
{
	return suit;
}

string
Suit::toString(Suit::SuitType suitType)
{
	switch(suitType)
	{
	    case Suit::SuitType::HEART  :
	    	return "heart_R";
	    	break;
	    case Suit::SuitType::CLUB  :
	    	return "club_B";
	    	break;
	    case Suit::SuitType::SPADE  :
	    	return "spade_B";
	    	break;
	    case Suit::SuitType::DIAMOND  :
	    	return "diamond_R";
	    	break;
	}
	return "";
}

Suit::SuitColor
Suit::getColor()
{
	return color;
}

int
Suit::getNumberOfCards()
{
	return numberOfCards;
}
