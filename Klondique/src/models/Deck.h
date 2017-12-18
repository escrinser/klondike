#ifndef DECK_H_
#define DECK_H_

#include <iostream>

#include <vector>
#include <memory>

#include "Card.h"
#include "Suit.h"
//class Card;
//class Suit;

using namespace std;

#define KING 13
#define ACE 1

#define NUMBER_OF_CARDS 13

class Deck {
private:
    vector<shared_ptr<Card>> deck;

public:
	Deck();
	virtual ~Deck();

	void loadDeck(vector<shared_ptr<Suit>>);

	vector<shared_ptr<Card>> shuffle();

    vector<shared_ptr<Card>> getDeck();

    int getNumberOfCards();

    MSGPACK_DEFINE(deck);

};

#endif /* DECK_H_ */
