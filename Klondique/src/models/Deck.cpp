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

//#define NUMBER_OF_CARDS 13

using namespace std;

Deck::Deck()
{
	/*vector<shared_ptr<Suit>> allSuites;

	allSuites.push_back(shared_ptr<Suit>(new Suit(SuitType::HEARTS, SuitColor::RED, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(SuitType::SPADE, SuitColor::BLACK, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(SuitType::CLUB, SuitColor::BLACK, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(SuitType::DIAMOND, SuitColor::RED, NUMBER_OF_CARDS)));

	loadDeck(allSuites);*/
}

Deck::~Deck() {
}

void
Deck::loadDeck(vector<shared_ptr<Suit>> theAllSuites)
{
	vector<shared_ptr<Suit>>::iterator it;

	for (it = theAllSuites.begin(); it != theAllSuites.end(); it++)
	{
		//int n = static_cast<int>(CardType::ACE); // OK, n = 1
		//cout << "Suit: " << (*it)->getSuit() << endl;
		for (int i=0; i < (*it)->getNumberOfCards() ; i++)
		{
			deck.push_back(shared_ptr<Card>(new Card((*it), i+1)));
			//deck.push_back(shared_ptr<Card>(new Card((*it), CardType[i])));
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

