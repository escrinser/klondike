/*
 * Factorial.cpp
 *
 *  Created on: 1 oct. 2017
 *      Author: eseogaz
 */
#include <iostream>

#include "Deck.h"

using namespace std;

int main()
{
   cout << "The First Version of Klondique." << endl;

   Deck deck;
   deck.loadDeck();

   vector<Card> initialDeck = deck.getDeck();


   vector<Card>::iterator it;  // declare an iterator to a vector of strings

   // now start at from the beginning
   // and keep iterating over the elements
   for(it = initialDeck.begin(); it != initialDeck.end(); it++)
   {
       // print
	   cout << "Card -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
   }

   vector<Card> shuffleDeck = deck.shuffle();

   // now start at from the beginning
   // and keep iterating over the elements
   for(vector<Card>::iterator it = shuffleDeck.begin(); it != shuffleDeck.end(); it++)
   {
       // print
	   cout << "Card -> number: " << (*it).getNumber() << ", suit: "
			   << (*it).getSuit().getSuit() << ", color: " << (*it).getSuit().getColor() << endl;
   }

   return 0;
}

// example: class constructor
/*#include <iostream>
#include "Rectangulo.h"

using namespace std;


class Rectangle {
    int width, height;
  public:
    Rectangle (int,int);
    int area () {return (width*height);}
};

Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}

int main () {
  Rectangle rect (3,4);
  Rectangle rectb (5,6);

  Rectangulo rectang (6,6);

  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  cout << "rectangulo area: " << rectang.area() << endl;
  return 0;
}*/

