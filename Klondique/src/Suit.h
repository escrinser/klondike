/*
 * Suit.h
 *
 *  Created on: 3 oct. 2017
 *      Author: Ana
 */

#ifndef SUIT_H_
#define SUIT_H_

#include <iostream>

using namespace std;

class Suit {
public:
	Suit();
	virtual ~Suit();

	Suit(string, string);

	string getSuit();
	string getColor();
private:
	string suit;
	string color;
};

#endif /* SUIT_H_ */
