#ifndef CARDINBOARD_H_
#define CARDINBOARD_H_

#include <iostream>

using namespace std;

#include "Card.h"

enum TurnedEnum {
	UP=0,
	DOWN
};

class CardInBoard {
public:
	CardInBoard();
	virtual ~CardInBoard();

	CardInBoard(shared_ptr<Card> card, TurnedEnum upOrDownTurn);

	shared_ptr<Card> getCard();

	TurnedEnum getUpOrDownTurned();
	void setUpOrDownTurned(TurnedEnum upOrDownTurn);

private:
	shared_ptr<Card> card;
	TurnedEnum upOrDownTurned;
};

#endif /* CARDINBOARD_H_ */
