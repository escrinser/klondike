/*
 * Factorial.cpp
 *
 *  Created on: 1 oct. 2017
 *      Author: eseogaz
 */
#include <iostream>

#include "Deck.h"
#include "KlondiqueBoard.h"

using namespace std;

int main()
{
   cout << "The First Version of Klondique." << endl;
   cout << "=== MENU ===." << endl;
   cout << "1.) Jugar" << endl;
   cout << "2.) Salir" << endl;

   Deck deck;
   deck.loadDeck();

   /*vector<Card> initialDeck = deck.getDeck();


   vector<Card>::iterator it;  // declare an iterator to a vector of strings

   // now start at from the beginning
   // and keep iterating over the elements
   for(it = initialDeck.begin(); it != initialDeck.end(); it++)
   {
       // print
	   cout << "Card -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
   }

   cout << "-- Shuffle--" << endl;
   vector<Card> shuffleDeck = deck.shuffle();

   // now start at from the beginning
   // and keep iterating over the elements
   for(vector<Card>::iterator it = shuffleDeck.begin(); it != shuffleDeck.end(); it++)
   {
       // print
	   cout << "Card -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
   }*/

   KlondiqueBoard board (deck);
   //board.initBoard();
   board.startPlayingBoard();
   board.deal();

   //First movement (upturned to Pile1)
   board.moveBetweenDealAndPile(board.getUpturnedDeck(), board.getPile1());

   //Second movement (Pile7 to Pile2)
   board.moveBetweenPiles(board.getPile7(), board.getPile2());

   //Third movement (Pile6 to FoundationHeart)
   // TODO: First movement to an empty vector
   //board.moveBetweenPileAndFoundation(board.getPile6(), board.getFoundationHeart());

   return 0;
}
