#ifndef DECK_H_
#define DECK_H_

#include <iostream>

#include <vector>
#include <memory>

class Card;
class Suit;

using namespace std;

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
