#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>
#include <memory>

#include "Suit.h"
#include "CardInBoard.h"

class Card;
class Deck;


using namespace std;

#define NUMBER_OF_PILES 7
#define NUMBER_OF_FOUNDATIONS 4

#define FOUNDATION_HEART 0
#define FOUNDATION_SPADE 1
#define FOUNDATION_CLUB 2
#define FOUNDATION_DIAMOND 3

class Board {
public:
	Board();
	virtual ~Board();

	Board(shared_ptr<Deck> theDeck);

	void startPlayingBoard();

	void deal();

	void moveBetweenPiles(int thePileOriginNumber,
		     	 	 	  int thePileDestinationNumber,
						  int theCardOriginNumber);

	void moveBetweenWastePileAndPile(int thePileDestinationNumber);
	void moveBetweenWastePileAndFoundation();
	void moveBetweenPileAndFoundation(int thePileOriginNumber);

	bool canMoveToPile(shared_ptr<Card> theCard, int thePileDestionationNumber);
	bool canMoveToFoundation(int theCardNumber, int foundationNumber);

	int giveMeTheFoundationNumber(SuitType theSuit);
	void upturnCardInPile(vector<CardInBoard> thePile);

	void showBoard();
	void showElement(vector<CardInBoard> theElement);

	bool hasWon();

	void clear();

	vector<CardInBoard> getStock();
	vector<CardInBoard> getWastePile();
	vector<vector<CardInBoard>> getPiles();
	vector<vector<CardInBoard>> getFoundations();

	void setStock(vector<CardInBoard> theStock);
	void setWastePile(vector<CardInBoard> theWastePile);
	void setPiles(vector<vector<CardInBoard>> thePiles);
	void setFoundations(vector<vector<CardInBoard>> theFoundations);

private:
	shared_ptr<Deck> deck;

	vector<CardInBoard> stock;
	vector<CardInBoard> wastePile;
	vector<vector<CardInBoard>> piles;
	vector<vector<CardInBoard>> foundations;

};

#endif /* BOARD_H_ */
