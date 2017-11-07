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
	//TODO: shared_pointers o con news
	//TODO: los objetos creados en un método sólo son locales al método, se almancenan en el stack (y al salir del método pum!! desaparecen)
	Suit* suitHeart = new Suit("heart", "red");
	Suit* suitSpade = new Suit("spade", "black");
	Suit* suitClub = new Suit("club", "black");
	Suit* suitDiamond = new Suit("diamond", "red");


	vector<Suit*> allSuites;
	allSuites.push_back(suitHeart);
	allSuites.push_back(suitSpade);
	allSuites.push_back(suitClub);
	allSuites.push_back(suitDiamond);

	vector<Suit*>::iterator it;

	//std::shared_ptr<int> p(new int);  // or '=shared_ptr<int>(new int)' if you insist
	//auto p = std::make_shared<int>(); // or 'std::shared_ptr<int> p' if you insist

	/*shared_ptr<Suit*> suitHeart (new Suit("heart", "red"));
	shared_ptr<Suit*> suitSpade (new Suit("spade", "black"));
	shared_ptr<Suit*> suitClub (new Suit("club", "black"));
	shared_ptr<Suit*> suitDiamond (new Suit("diamond", "red"));

	vector<shared_ptr<Suit*>> allSuites;
	allSuites.push_back(move(suitHeart));
	allSuites.push_back(move(suitSpade));
	allSuites.push_back(move(suitClub));
	allSuites.push_back(move(suitDiamond));*/

	/*vector<shared_ptr<Suit>> allSuites;
	allSuites.push_back(shared_ptr<Suit>(new Suit("heart", "red")));
	allSuites.push_back(shared_ptr<Suit>(new Suit("spade", "black")));
	allSuites.push_back(shared_ptr<Suit>(new Suit("club", "black")));
	allSuites.push_back(shared_ptr<Suit>(new Suit("diamond", "red")));

	vector<shared_ptr<Suit>>::iterator it;*/

	for (it = allSuites.begin(); it != allSuites.end(); it++)
	{
		cout << "Suit: " << (*it)->getSuit() << endl;
		for (int i=1; i < 14 ; i++) //TODO: Magic number 14.
		{
			//deck.push_back(shared_ptr<Card>(new Card((*it), i)));
			deck.push_back(new Card((*it), i));
		}
	}

	cout << "The First Version of the Deck with this number of cards: " << deck.size() << endl;
}

vector<Card*>
Deck::getDeck()
{
	return deck;
}

int
Deck::getNumberOfCards()
{
	return deck.size();
}

vector<Card*>
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

