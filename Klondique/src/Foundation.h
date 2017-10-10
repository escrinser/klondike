/*
 * Foundation.h
 *
 *  Created on: 10 oct. 2017
 *      Author: eseogaz
 */

#ifndef FOUNDATION_H_
#define FOUNDATION_H_

#include <vector>

#include "CardInBoard.h"

class Foundation {
public:
	Foundation();
	virtual ~Foundation();
	Foundation(Suit suit, vector<CardInBoard> cards);


	void print();
	vector<CardInBoard> getCards();
	Suit getSuit();

	Suit suit;
	vector<CardInBoard> cards;
};

#endif /* FOUNDATION_H_ */
