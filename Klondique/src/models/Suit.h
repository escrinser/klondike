#ifndef SUIT_H_
#define SUIT_H_

#include <iostream>

using namespace std;

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

class Suit {
public:
	Suit();
	virtual ~Suit();

	Suit(SuitType, SuitColor, int);

	SuitColor getColor();
	int getNumberOfCards();
	SuitType getSuit();
	string toString(SuitType suitType);
private:
	SuitType suit;
	SuitColor color;
	int numberOfCards;
};

#endif /* SUIT_H_ */
