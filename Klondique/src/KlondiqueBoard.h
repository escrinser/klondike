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
#include "CardInBoard.h"
#include "Pile.h"
#include "Foundation.h"

class KlondiqueBoard {
public:
	KlondiqueBoard();
	virtual ~KlondiqueBoard();

	KlondiqueBoard(Deck);
	KlondiqueBoard(Deck, vector<Pile>, vector<Foundation>);

	void initBoard();
	void startPlayingBoard();
	void startPlayingBoard2();

	int deal();
	bool moveBetweenPiles(vector<CardInBoard>& thePileOrigin,
		     	 	 	  vector<CardInBoard>& thePileDestination,
						  int theCardOriginNumber);
	bool moveBetweenPileAndFoundation(vector<CardInBoard>& thePileOrigin,
	  	  	  	  	 	 	 	 	  vector<CardInBoard>& theFoundationDestination,
									  int theFoundationNumber);

	//TODO: Similar movement as moveBetweenPiles (refactoring)
	bool moveBetweenWastePileAndPile(vector<CardInBoard>& theWastePileOrigin,
			   	   	   	   	    vector<CardInBoard>& thePileDestination);

	bool moveBetweenWastePileAndPile(int thePileDestinationNumber);

	vector<CardInBoard> giveMeThePile(int thePileDestinationNumber);

	//TODO: Similar movement as moveBetweenPileAndFoundation (refactoring)
	bool moveBetweenWastePileAndFoundation(vector<CardInBoard>& theWastePileOrigin,
									  vector<CardInBoard>& theFoundationDestination,
									  int theFoundationNumber);

	vector<CardInBoard>& getWastePile();
	vector<CardInBoard>& getStock();

	vector<CardInBoard>& getPile1();
	vector<CardInBoard>& getPile2();
	vector<CardInBoard>& getPile3();
	vector<CardInBoard>& getPile4();
	vector<CardInBoard>& getPile5();
	vector<CardInBoard>& getPile6();
	vector<CardInBoard>& getPile7();

	vector<CardInBoard>& getFoundationHeart();
	vector<CardInBoard>& getFoundationSpade();
	vector<CardInBoard>& getFoundationClub();
	vector<CardInBoard>& getFoundationDiamond();

	void showBoard();
	void showElement(vector<CardInBoard>& theElement);

	bool upturnCardInPile(vector<CardInBoard>& thePile);

private:
	Deck deck;

	vector<Pile> piles;
	vector<Foundation> foundations;

	vector<CardInBoard> stock;
	vector<CardInBoard> wastePile;


	vector<CardInBoard> pile1;
	vector<CardInBoard> pile2;
	vector<CardInBoard> pile3;
	vector<CardInBoard> pile4;
	vector<CardInBoard> pile5;
	vector<CardInBoard> pile6;
	vector<CardInBoard> pile7;

	vector<CardInBoard> foundationHeart;
	vector<CardInBoard> foundationSpade;
	vector<CardInBoard> foundationClub;
	vector<CardInBoard> foundationDiamond;

};

#endif /* KLONDIQUEBOARD_H_ */
