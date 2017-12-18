#ifndef CARDINBOARD_H_
#define CARDINBOARD_H_

#include <iostream>

using namespace std;

#include "Card.h"
#include <msgpack.hpp>

class CardInBoard {
public:
enum TurnedEnum {
	UP=0,
	DOWN
};

private:
	shared_ptr<Card> card;
	CardInBoard::TurnedEnum upOrDownTurned;

public:
	CardInBoard();
	virtual ~CardInBoard();

	CardInBoard(shared_ptr<Card> card, CardInBoard::TurnedEnum upOrDownTurn);

	shared_ptr<Card> getCard();

	CardInBoard::TurnedEnum getUpOrDownTurned();
	void setUpOrDownTurned(CardInBoard::TurnedEnum upOrDownTurn);

	MSGPACK_DEFINE(card, upOrDownTurned);
};

MSGPACK_ADD_ENUM(CardInBoard::TurnedEnum);
#endif /* CARDINBOARD_H_ */
