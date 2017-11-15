#include "CardInBoard.h"

CardInBoard::CardInBoard() {
}

CardInBoard::~CardInBoard() {
}

CardInBoard::CardInBoard(shared_ptr<Card> theCard, TurnedEnum theUpOrDownTurn)
{
	card = theCard;
	upOrDownTurned = theUpOrDownTurn;
}

shared_ptr<Card>
CardInBoard::getCard()
{
	return card;
}

TurnedEnum
CardInBoard::getUpOrDownTurned()
{
	return upOrDownTurned;
}

void
CardInBoard::setUpOrDownTurned(TurnedEnum theUpOrDownTurned)
{
	upOrDownTurned = theUpOrDownTurned;
}
