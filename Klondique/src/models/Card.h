/*
 * Card.h
 *
 *  Created on: 3 oct. 2017
 *      Author: eseogaz
 */

#ifndef CARD_H_
#define CARD_H_

#include <memory>

#include "Suit.h"

class Suit;

enum CardType {
	ACE=1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	JACK,
	QUEEN,
	KING
};

class Card {
public:
	Card();
	virtual ~Card();

	Card(shared_ptr<Suit>, int);
	//Card(shared_ptr<Suit>, CardType);

	shared_ptr<Suit> getSuit();
	int getNumber();
	//CardType getType();

private:
	shared_ptr<Suit> suit;
	int number;
	//CardType cardType;
};

#endif /* CARD_H_ */
