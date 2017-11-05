/*
 * Card.h
 *
 *  Created on: 3 oct. 2017
 *      Author: eseogaz
 */

#ifndef CARD_H_
#define CARD_H_

#include "Suit.h"

class Card {
public:
	Card();
	virtual ~Card();

	Card(Suit*, int);

	Suit* getSuit();
	int getNumber();

private:
	Suit* suit;
	int number;
};

#endif /* CARD_H_ */
