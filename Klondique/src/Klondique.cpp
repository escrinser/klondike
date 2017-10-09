/*
 * Factorial.cpp
 *
 *  Created on: 1 oct. 2017
 *      Author: eseogaz
 */
#include <iostream>

#include "Play.h"

using namespace std;

int main()
{
   int choice;
   cout << "The First Version of Klondique." << endl;
   do
   {
	   cout << "Chose one option:\n\n";

	   cout << "1  Play\n";
	   cout << "2  End\n";
	   cout << "Enter your choice and press return: ";
	   cin >> choice;
	   Play start;
	   switch (choice)
	   {
		   case 1:
			   cout << "Start playing"<<endl;
			   start.startPlay();
			   break;

		   case 2:
			   cout << "End of the game."<<endl;
			   break;

		   default:
			   cout << "Not a Valid Choice. Choose again.\n";
			   break;
	   }
   }
   while (choice != 1 && choice != 2);

   return 0;
}

/*void
play()
{
   Deck deck;
   deck.loadDeck();

   KlondiqueBoard board (deck);
   //board.initBoard();
   board.startPlayingBoard();
   board.deal();

   //First movement (upturned to Pile1)
   cout << "First movement (upturned to Pile1)" << endl;
   board.moveBetweenDealAndPile(board.getUpturnedDeck(), board.getPile1());

   //Second movement (Pile7 to Pile2)
   cout << "Second movement (Pile7 to Pile2)" << endl;
   board.moveBetweenPiles(board.getPile7(), board.getPile2());

   //Third movement (Pile6 to FoundationHeart)
   // TODO: First movement to an empty vector
   cout << "Third movement (Pile6 to FoundationHeart)" << endl;
   board.moveBetweenPileAndFoundation(board.getPile6(), board.getFoundationHeart());
}*/
