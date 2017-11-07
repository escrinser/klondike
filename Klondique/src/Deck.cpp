/*
 * Deck.cpp
 *
 *  Created on: 3 oct. 2017
 *      Author: eseogaz
 */

#include "Deck.h"

#include "Suit.h"
#include "Card.h"

// random_shuffle
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <memory>


Deck::Deck() {
}

Deck::~Deck() {
}

void
Deck::loadDeck()
{
	vector<shared_ptr<Suit>> allSuites;
	allSuites.push_back(shared_ptr<Suit>(new Suit("heart", "red")));
	allSuites.push_back(shared_ptr<Suit>(new Suit("spade", "black")));
	allSuites.push_back(shared_ptr<Suit>(new Suit("club", "black")));
	allSuites.push_back(shared_ptr<Suit>(new Suit("diamond", "red")));

	vector<shared_ptr<Suit>>::iterator it;

	for (it = allSuites.begin(); it != allSuites.end(); it++)
	{
		//cout << "Suit: " << (*it)->getSuit() << endl;
		for (int i=1; i < 14 ; i++) //TODO: Magic number 14.
		{
			deck.push_back(shared_ptr<Card>(new Card((*it), i)));
		}
	}

	cout << "The First Version of the Deck with this number of cards: " << deck.size() << endl;
}

vector<shared_ptr<Card>>
Deck::getDeck()
{
	return deck;
}

int
Deck::getNumberOfCards()
{
	return deck.size();
}

vector<shared_ptr<Card>>
Deck::shuffle()
{
	std::srand ( unsigned ( std::time(0) ) );

	// using built-in random generator:
	std::random_shuffle (deck.begin(), deck.end());

	// using myrandom:
	// random generator function:
	//int myrandom (int i) { return std::rand()%i;}
	//std::random_shuffle ( theShuffleDeck.begin(), theShuffleDeck.end(), myrandom);

	return deck;
}

