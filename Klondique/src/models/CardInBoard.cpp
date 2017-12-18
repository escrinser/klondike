#include "CardInBoard.h"

CardInBoard::CardInBoard() {
}

CardInBoard::~CardInBoard() {
}

CardInBoard::CardInBoard(shared_ptr<Card> theCard, CardInBoard::TurnedEnum theUpOrDownTurn)
{
	card = theCard;
	upOrDownTurned = theUpOrDownTurn;
}

shared_ptr<Card>
CardInBoard::getCard()
{
	return card;
}

CardInBoard::TurnedEnum
CardInBoard::getUpOrDownTurned()
{
	return upOrDownTurned;
}

void
CardInBoard::setUpOrDownTurned(CardInBoard::TurnedEnum theUpOrDownTurned)
{
	upOrDownTurned = theUpOrDownTurned;
}
