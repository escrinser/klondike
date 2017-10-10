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
