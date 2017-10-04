/*
 * CardInBoard.h
 *
 *  Created on: 4 oct. 2017
 *      Author: Ana
 */

#ifndef CARDINBOARD_H_
#define CARDINBOARD_H_

#include "Card.h"

class CardInBoard {
public:
	CardInBoard();
	virtual ~CardInBoard();

	CardInBoard(Card, string);

	Card getCard();
	string getUpOrDownTurned();
	void setUpOrDownTurned(string);

private:
	Card card;
	string upOrDownTurned;
};

#endif /* CARDINBOARD_H_ */
