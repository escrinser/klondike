/*
 * Deck.cpp
 *
 *  Created on: 3 oct. 2017
 *      Author: eseogaz
 */

#include "Deck.h"

#include "Suit.h"

// random_shuffle
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand


Deck::Deck() {
	// TODO Auto-generated constructor stub

}

Deck::~Deck() {
	// TODO Auto-generated destructor stub
}

void
Deck::loadDeck()
{
	Suit suitHeart("heart", "red");
	Suit suitSpade("spade", "black");
	Suit suitClub("club", "black");
	Suit suitDiamond("diamond", "red");

	vector<Suit> allSuites;
	allSuites.push_back(suitHeart);
	allSuites.push_back(suitSpade);
	allSuites.push_back(suitClub);
	allSuites.push_back(suitDiamond);

	vector<Suit>::iterator it;

	for (it = allSuites.begin(); it != allSuites.end(); it++)
	{
		cout << "Suit: " << (*it).getSuit() << endl;
		for (int i=1; i < 14 ; i++)
		{
			Card card((*it), i);

			deck.push_back(card);
		}
	}

	cout << "The First Version of the Deck with this number of cards: " << deck.size() << endl;
}

vector<Card>
Deck::getDeck()
{
	return deck;
}

int
Deck::getNumberOfCards()
{
	return deck.size();
}

vector<Card>
Deck::shuffle()
{
	vector<Card> theShuffleDeck = deck;

	std::srand ( unsigned ( std::time(0) ) );

	// using built-in random generator:
	std::random_shuffle ( theShuffleDeck.begin(), theShuffleDeck.end() );

	// using myrandom:
	// random generator function:
	//int myrandom (int i) { return std::rand()%i;}
	//std::random_shuffle ( theShuffleDeck.begin(), theShuffleDeck.end(), myrandom);

	return theShuffleDeck;
}

