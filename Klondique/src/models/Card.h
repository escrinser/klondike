#ifndef CARD_H_
#define CARD_H_

#include <memory>

#include "Suit.h"
//#include "Suit.cpp"

class Card {
private:
	shared_ptr<Suit> suit;
	int number;

public:
	Card();
	virtual ~Card();

	Card(shared_ptr<Suit>, int);

	shared_ptr<Suit> getSuit();
	int getNumber();

	//MSGPACK_DEFINE(number);
	MSGPACK_DEFINE(suit, number);
};

#endif /* CARD_H_ */
