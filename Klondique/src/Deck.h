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

#include <set>
#include <vector>
#include <list>
#include <memory>

#include "Card.h"

using namespace std; //Import the standard library

class Deck {
public:
	Deck();
	virtual ~Deck();

	void loadDeck();

    vector<Card> shuffle();

    vector<Card> getDeck();

    int getNumberOfCards();

private:
    vector<Card> deck;

};

#endif /* DECK_H_ */
