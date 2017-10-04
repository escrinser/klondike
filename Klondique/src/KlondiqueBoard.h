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

#ifndef KLONDIQUEBOARD_H_
#define KLONDIQUEBOARD_H_

#include "Deck.h"

class KlondiqueBoard {
public:
	KlondiqueBoard();
	virtual ~KlondiqueBoard();

	int deal();
	int moveBetweenPiles();
	int moveBetweenPileAndFoundation();
	int moveBetweenDealAndPile();

	vector<Card> getPile1();
	vector<Card> getPile2();
	vector<Card> getPile3();
	vector<Card> getPile4();
	vector<Card> getPile5();
	vector<Card> getPile6();
	vector<Card> getPile7();

	vector<Card> getFoundationHeart();
	vector<Card> getFoundationSpade();
	vector<Card> getFoundationClub();
	vector<Card> getFoundationDiamond();

	void showBoard();

	void upturnCardInPile();

private:
	Deck downturnedDeck;
	Deck upturnedDeck;

	vector<Card> pile1;
	vector<Card> pile2;
	vector<Card> pile3;
	vector<Card> pile4;
	vector<Card> pile5;
	vector<Card> pile6;
	vector<Card> pile7;

	vector<Card> fountationHeart;
	vector<Card> fountationSpade;
	vector<Card> fountationClub;
	vector<Card> fountationDiamond;

	//vector<Card, string> cardInBoard;
};

#endif /* KLONDIQUEBOARD_H_ */
