/*
 * CardInBoard.cpp
 *
 *  Created on: 4 oct. 2017
 *      Author: Ana
 */

#include "CardInBoard.h"

CardInBoard::CardInBoard() {
}

CardInBoard::~CardInBoard() {
}

CardInBoard::CardInBoard(Card* theCard, string theUpOrDownTurned)
{
	card = theCard;
	upOrDownTurned = theUpOrDownTurned;
}

Card*
CardInBoard::getCard()
{
	return card;
}

string
CardInBoard::getUpOrDownTurned()
{
	return upOrDownTurned;
}

void
CardInBoard::setUpOrDownTurned(string theUpOrDownTurned)
{
	upOrDownTurned = theUpOrDownTurned;
}
