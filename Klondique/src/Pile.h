/*
 * Pile.h
 *
 *  Created on: 10 oct. 2017
 *      Author: eseogaz
 */

#ifndef PILE_H_
#define PILE_H_

#include <vector>

#include "CardInBoard.h"

class Pile {
public:
	Pile();
	Pile(int number, vector<CardInBoard> cards);
	virtual ~Pile();

	void print();
	vector<CardInBoard> getCards();
	int getNumber();

	int number;
	vector<CardInBoard> cards;
};

#endif /* PILE_H_ */
