#ifndef CARD_H_
#define CARD_H_

#include <memory>

#include "Suit.h"

class Suit;

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
