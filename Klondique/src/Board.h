/*
 * KlondiqueBoard.h
 *
 *  Created on: 3 oct. 2017
 *      Author: Ana
 */
/*
 * Class Board (7 piles, 4 foundations, deck downside, card upturned beside deck (downturned))
	variables:
		Deck (52 cards at the begining)
		Deal (52- (1+2+3+4+5+6+7) = 52-28 = 24 cards maximum)
		7 piles (14, 15, 16, 17, 18, 19, 20 cards maximum)
		4 foundations (13 cards maximum)
		Card from Deck (vector of Card and upturned o downturned)

	methods:
		deal
		moveBetweenPiles
		moveBetweenPileAndFoundation
		moveBetweenDealAndPile*/

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>

#include "Deck.h"
#include "Card.h"
#include "CardInBoard.h"
//class Deck;
//class CardInBoard;

using namespace std;

class Board {
public:
	Board();
	virtual ~Board();

	Board(Deck*);

	void initBoard();
	void startPlayingBoard();

	int deal();

	bool moveBetweenPiles(int thePileOriginNumber,
		     	 	 	  int thePileDestinationNumber,
						  int theCardOriginNumber);

	bool moveBetweenWastePileAndPile(int thePileDestinationNumber);

	int giveMeTheFoundationFromCard(vector<CardInBoard*> theOrigin);

	bool moveBetweenWastePileAndFoundation();
	bool moveBetweenPileAndFoundation(int thePileOriginNumber);

	vector<CardInBoard*> getWastePile();
	vector<CardInBoard*> getStock();

	/*vector<CardInBoard*> getFoundationHeart();
	vector<CardInBoard*> getFoundationSpade();
	vector<CardInBoard*> getFoundationClub();
	vector<CardInBoard*> getFoundationDiamond();*/
	vector<vector<CardInBoard*>> getFoundations();

	void showBoard();
	void showElement(vector<CardInBoard*> theElement);

	bool upturnCardInPile(vector<CardInBoard*> thePile);

private:
	Deck* deck;

	vector<CardInBoard*> stock;
	vector<CardInBoard*> wastePile;

	vector<vector<CardInBoard*>> piles;

	vector<CardInBoard*> foundationHeart;
	vector<CardInBoard*> foundationSpade;
	vector<CardInBoard*> foundationClub;
	vector<CardInBoard*> foundationDiamond;

	vector<vector<CardInBoard*>> foundations;

};

#endif /* BOARD_H_ */
