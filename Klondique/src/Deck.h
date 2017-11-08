/*
 * Deck.h
 *
 *  Created on: 3 oct. 2017
 *      Author: eseogaz
 */

#ifndef DECK_H_
#define DECK_H_

// C++ libraries
#include <iostream>

//#include <set>
#include <vector>
//#include <list>
#include <memory>

class Card;
class Suit;

using namespace std; //Import the standard library

class Deck {
public:
	Deck();
	virtual ~Deck();

	void loadDeck(vector<shared_ptr<Suit>>);

    vector<shared_ptr<Card>> shuffle();

    vector<shared_ptr<Card>> getDeck();

    int getNumberOfCards();

private:
    vector<shared_ptr<Card>> deck;

};

#endif /* DECK_H_ */
