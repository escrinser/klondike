/*
 * CardInBoard.h
 *
 *  Created on: 4 oct. 2017
 *      Author: Ana
 */

#ifndef CARDINBOARD_H_
#define CARDINBOARD_H_

#include <iostream>

using namespace std;

#include "Card.h"

class CardInBoard {
public:
	CardInBoard();
	virtual ~CardInBoard();

	CardInBoard(Card*, string upOrDownTurned);

	Card* getCard();
	string getUpOrDownTurned();
	void setUpOrDownTurned(string upOrDownTurned);

private:
	Card* card;
	string upOrDownTurned;
};

#endif /* CARDINBOARD_H_ */
