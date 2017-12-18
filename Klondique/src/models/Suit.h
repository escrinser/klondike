#ifndef SUIT_H_
#define SUIT_H_

#include <iostream>
#include <msgpack.hpp>

using namespace std;

class Suit {

public:
enum SuitType {
	HEART=0,
	SPADE,
	CLUB,
	DIAMOND
};

enum SuitColor{
	RED=0,
	BLACK
};

private:
    Suit::SuitType suit;
    Suit::SuitColor color;
	int numberOfCards;

public:
	Suit();
	virtual ~Suit();

	Suit(Suit::SuitType, Suit::SuitColor, int);

	Suit::SuitColor getColor();
	int getNumberOfCards();
	Suit::SuitType getSuit();
	string toString(Suit::SuitType suitType);
	MSGPACK_DEFINE(suit, color);
};

MSGPACK_ADD_ENUM(Suit::SuitType);
MSGPACK_ADD_ENUM(Suit::SuitColor);
#endif /* SUIT_H_ */
