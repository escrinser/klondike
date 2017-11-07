/*
 * Card.h
 *
 *  Created on: 3 oct. 2017
 *      Author: eseogaz
 */

#ifndef CARD_H_
#define CARD_H_

#include "Suit.h"
#include <memory>

class Card {
public:
	Card();
	virtual ~Card();

	Card(shared_ptr<Suit>, int);

	shared_ptr<Suit> getSuit();
	int getNumber();

private:
	shared_ptr<Suit> suit;
	int number;
};

#endif /* CARD_H_ */
