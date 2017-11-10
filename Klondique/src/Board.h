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
#include <memory>

class Card;
class Deck;
class CardInBoard;

using namespace std;

class Board {
public:
	Board();
	virtual ~Board();

	Board(shared_ptr<Deck> theDeck);

	void initBoard();
	void startPlayingBoard();

	int deal();

	bool moveBetweenPiles(int thePileOriginNumber,
		     	 	 	  int thePileDestinationNumber,
						  int theCardOriginNumber);

	bool moveBetweenWastePileAndPile(int thePileDestinationNumber);

	int giveMeTheFoundationFromCard(vector<shared_ptr<CardInBoard>> theOrigin);

	bool moveBetweenWastePileAndFoundation();
	bool moveBetweenPileAndFoundation(int thePileOriginNumber);

	vector<shared_ptr<CardInBoard>> getWastePile();
	vector<shared_ptr<CardInBoard>> getStock();

	vector<vector<shared_ptr<CardInBoard>>> getFoundations();

	void showBoard();
	void showElement(vector<shared_ptr<CardInBoard>> theElement);

	bool upturnCardInPile(vector<shared_ptr<CardInBoard>> thePile);

	bool hasWon();

	void clear();

private:
	shared_ptr<Deck> deck;
	//vector<shared_ptr<Card>> deck;

	vector<shared_ptr<CardInBoard>> stock;
	vector<shared_ptr<CardInBoard>> wastePile;
	vector<vector<shared_ptr<CardInBoard>>> piles;
	vector<vector<shared_ptr<CardInBoard>>> foundations;

};

#endif /* BOARD_H_ */
