/*
 * KlondiqueBoard.cpp
 *
 *  Created on: 3 oct. 2017
 *      Author: Ana
 */

#include "KlondiqueBoard.h"
#include "CardInBoard.h"

KlondiqueBoard::KlondiqueBoard() {
	// TODO Auto-generated constructor stub

}

KlondiqueBoard::~KlondiqueBoard() {
	// TODO Auto-generated destructor stub
}

KlondiqueBoard::KlondiqueBoard(Deck theDeck)
{
	deck = theDeck;
}

KlondiqueBoard::KlondiqueBoard(Deck theDeck, vector<Pile> thePiles, vector<Foundation> theFoundations)
{
	deck = theDeck;
	piles = thePiles;
	foundations = theFoundations;
}

void
KlondiqueBoard::initBoard()
{
	// stock
	vector<Card> initialDeck = deck.getDeck();
	//vector<Card> initialDeck = deck.shuffle();

	for(vector<Card>::iterator it = initialDeck.begin(); it != initialDeck.end(); it++)
	{
	   stock.push_back(CardInBoard ((*it), "downturned"));
	}

	// upturnedDeck empty

	// Foundation Hearts empty
	// Foundation Spades empty
	// Foundation Clubs empty
	// Foundation Diamonds empty

	// Pile1 empty
	// Pile2 empty
	// Pile3 empty
	// Pile4 empty
	// Pile5 empty
	// Pile6 empty
	// Pile7 empty
    cout << "INIT BOARD" << endl;
	showBoard();
	cout << "END OF INIT BOARD" << endl;

}

void
KlondiqueBoard::startPlayingBoard()
{
	vector<Card> initialDeck = deck.shuffle();
	// upturnedDeck empty

	// Foundation Hearts empty
	// Foundation Spades empty
	// Foundation Clubs empty
	// Foundation Diamonds empty

	// Pile1
	pile1.push_back(CardInBoard (initialDeck.back(), "upturned"));
	cout << "Before Pile 1: " << initialDeck.size() << endl;
	initialDeck.pop_back();
	cout << "After Pile 1: "<< initialDeck.size() << endl;

	// Pile2
	pile2.push_back(CardInBoard (initialDeck.back(), "downturned"));
	initialDeck.pop_back();
	pile2.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	cout << "After Pile 2: "<< initialDeck.size() << endl;

	// Pile3
	for (int x=0; x<2; x++)
	{
		pile3.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile3.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	cout << "After Pile 3: "<< initialDeck.size() << endl;

	// Pile4
	for (int x=0; x<3; x++)
	{
		pile4.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile4.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	cout << "After Pile 4: "<< initialDeck.size() << endl;

	// Pile5
	for (int x=0; x<4; x++)
	{
		pile5.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile5.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	cout << "After Pile 5: "<< initialDeck.size() << endl;

	// Pile6
	for (int x=0; x<5; x++)
	{
		pile6.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile6.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	cout << "After Pile 6: "<< initialDeck.size() << endl;

	// Pile7
	for (int x=0; x<6; x++)
	{
		pile7.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile7.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	cout << "After Pile 7: "<< initialDeck.size() << endl;

	// stock
	cout << "Stock number of cards: "<< initialDeck.size() << endl;
	for(vector<Card>::iterator it = initialDeck.begin(); it != initialDeck.end(); it++)
	{
	   stock.push_back(CardInBoard ((*it), "downturned"));
	}

	cout << "INIT PLAYING BOARD" << endl;
	showBoard();
	cout << "END OF INIT PLAYING BOARD" << endl;
}

int
KlondiqueBoard::deal()
{
	if (!stock.empty())
	{
		wastePile.push_back(stock.back());
		wastePile.back().setUpOrDownTurned("upturned");
		stock.pop_back();
		cout << "DEAL A CARD" << endl;
		showBoard();
		cout << "END OF DEAL A CARD" << endl;
	}
	else
	{
		cout << "There is no cards in stock - Put them in Stock again" << endl;

		while (!wastePile.empty())
		{
			stock.push_back(wastePile.back());
			stock.back().setUpOrDownTurned("downturned");
			wastePile.pop_back();
		}

		cout << "Ready to deal again" << endl;
		deal();
	}
	return 0;
}

//TODO: Move more than one card between Piles

bool
KlondiqueBoard::moveBetweenPiles(vector<CardInBoard> &thePileOrigin,
							     vector<CardInBoard> &thePileDestination)
{
	//return 0 -> no movement (not possible, no same pile, same color or not the next number)
	bool movementCorrect = false;

	//cout << "Prueba Número: " << thePileOrigin.back().getCard().getNumber() << " vs " << (thePileDestination.back().getCard().getNumber() - 1)  << endl;
	//cout << "Prueba Color: " << thePileOrigin.back().getCard().getSuit().getColor() << " != " << thePileDestination.back().getCard().getSuit().getColor() << endl;

	//Move a king to a empty Pile (other card is not allowed)
	if (thePileDestination.empty())
	{
		cout << "ONLY A KING IS ALLOW FROM PILE TO EMPTY PILE" << endl;
		if (thePileOrigin.back().getCard().getNumber()==13)
		{
			// Movement
			thePileDestination.push_back(thePileOrigin.back());
			thePileOrigin.pop_back();
			movementCorrect = true;
			cout << "MOVE A KING FROM PILE TO EMPTY PILE" << endl;
			showBoard();
			cout << "END OF MOVE A KING FROM PILE TO EMPTY PILE" << endl;
		}
		else
		{
			cout << "Not possible movement" << endl;
		}
	}
	else
	{
		if ((thePileOrigin.back().getCard().getNumber() ==
					(thePileDestination.back().getCard().getNumber() - 1)) &&
						(thePileOrigin.back().getCard().getSuit().getColor() !=
							(thePileDestination.back().getCard().getSuit().getColor())))
		{
			// Movement
			thePileDestination.push_back(thePileOrigin.back());
			thePileOrigin.pop_back();
			movementCorrect = true;
			cout << "MOVE A CARD FROM PILE TO PILE" << endl;
			showBoard();
			cout << "END OF MOVE A CARD FROM PILE TO PILE" << endl;
		}
		else
		{
			cout << "Not possible movement" << endl;
		}
	}

	bool upturnCard = false;
	if (movementCorrect)
	{
		upturnCard = upturnCardInPile(thePileOrigin);
	}
	return movementCorrect && upturnCard;
}

bool
KlondiqueBoard::moveBetweenPileAndFoundation(vector<CardInBoard>& thePileOrigin,
		          	  	  	  	  	  	  	 vector<CardInBoard>& theFoundationDestination)
{
	//return 0 -> no movement (not possible, different suit or not the next number)
	bool movementCorrect = false;

	//cout << "Prueba Número: " << thePileOrigin.back().getCard().getNumber() << " vs " << (theFoundationDestination.back().getCard().getNumber() - 1)  << endl;
	//cout << "Prueba Color: " << thePileOrigin.back().getCard().getSuit().getColor() << " != " << theFoundationDestination.back().getCard().getSuit().getColor() << endl;

	if(theFoundationDestination.empty())
	{
		if (thePileOrigin.back().getCard().getNumber() == 1)
		{
			// Movement
			theFoundationDestination.push_back(thePileOrigin.back());
			thePileOrigin.pop_back();
			movementCorrect = true;
			cout << "MOVE A CARD FROM PILE TO FOUNDATION" << endl;
			showBoard();
			cout << "END OF MOVE A CARD FROM PILE TO FOUNDATION" << endl;
		}
		else
		{
			cout << "Not possible movement" << endl;
		}
	}
	else
	{
		if ((thePileOrigin.back().getCard().getNumber() ==
				(theFoundationDestination.back().getCard().getNumber() - 1)) &&
					(thePileOrigin.back().getCard().getSuit().getSuit() ==
						(theFoundationDestination.back().getCard().getSuit().getSuit())))
		{
			// Movement
			theFoundationDestination.push_back(thePileOrigin.back());
			thePileOrigin.pop_back();
			movementCorrect = true;
			cout << "MOVE A CARD FROM PILE TO FOUNDATION" << endl;
			showBoard();
			cout << "END OF MOVE A CARD FROM PILE TO FOUNDATION" << endl;
		}
		else
		{
			cout << "Not possible movement" << endl;
		}
	}

	bool upturnCard = false;
	if (movementCorrect)
	{
		upturnCard = upturnCardInPile(thePileOrigin);
	}
	return movementCorrect && upturnCard;
}

bool
KlondiqueBoard::moveBetweenWastePileAndPile(vector<CardInBoard>& theDealOrigin,
									   vector<CardInBoard>& thePileDestination)
{
	//return 0 -> no movement (not possible, same color or not the next number)
	bool movementCorrect = false;

	//cout << "Prueba Número: " << theDealOrigin.back().getCard().getNumber() << " vs " << (thePileDestination.back().getCard().getNumber() - 1)  << endl;
	//cout << "Prueba Color: " << theDealOrigin.back().getCard().getSuit().getColor() << " != " << thePileDestination.back().getCard().getSuit().getColor() << endl;

	if ((theDealOrigin.back().getCard().getNumber() ==
			(thePileDestination.back().getCard().getNumber() - 1)) &&
				(theDealOrigin.back().getCard().getSuit().getColor() !=
					(thePileDestination.back().getCard().getSuit().getColor())))
	{
		// Movement
		thePileDestination.push_back(theDealOrigin.back());
		theDealOrigin.pop_back();
		movementCorrect = true;
		cout << "MOVE A CARD FROM DEAL TO PILE" << endl;
		showBoard();
		cout << "END OF MOVE A CARD FROM DEAL TO PILE" << endl;
	}
	else
	{
		cout << "Not possible movement" << endl;
	}

	return movementCorrect;
}

bool
KlondiqueBoard::moveBetweenWastePileAndFoundation(vector<CardInBoard>& theDealOrigin,
									   vector<CardInBoard>& theFoundationDestination)
{
	//return 0 -> no movement (not possible, different suit or not the next number)
	bool movementCorrect = false;

	//cout << "Prueba Número: " << theDealOrigin.back().getCard().getNumber() << " vs " << (theFoundationDestination.back().getCard().getNumber() - 1)  << endl;
	//cout << "Prueba Color: " << theDealOrigin.back().getCard().getSuit().getColor() << " != " << theFoundationDestination.back().getCard().getSuit().getColor() << endl;

	if(theFoundationDestination.empty())
	{
		if (theDealOrigin.back().getCard().getNumber() == 1)
		{
			// Movement
			theFoundationDestination.push_back(theDealOrigin.back());
			theDealOrigin.pop_back();
			movementCorrect = true;
			cout << "MOVE A CARD FROM PILE TO FOUNDATION" << endl;
			showBoard();
			cout << "END OF MOVE A CARD FROM PILE TO FOUNDATION" << endl;
		}
		else
		{
			cout << "Not possible movement" << endl;
		}
	}
	else
	{
		if ((theDealOrigin.back().getCard().getNumber() ==
				(theFoundationDestination.back().getCard().getNumber() - 1)) &&
					(theDealOrigin.back().getCard().getSuit().getSuit() ==
						(theFoundationDestination.back().getCard().getSuit().getSuit())))
		{
			// Movement
			theFoundationDestination.push_back(theDealOrigin.back());
			theDealOrigin.pop_back();
			movementCorrect = true;
			cout << "MOVE A CARD FROM PILE TO FOUNDATION" << endl;
			showBoard();
			cout << "END OF MOVE A CARD FROM PILE TO FOUNDATION" << endl;
		}
		else
		{
			cout << "Not possible movement" << endl;
		}
	}
	return movementCorrect;
}

bool
KlondiqueBoard::upturnCardInPile(vector<CardInBoard>& thePile)
{
	bool upturnedCorrect = false;

	if(!thePile.empty())
	{
		if (thePile.back().getUpOrDownTurned() == "downturned")
		{
			thePile.back().setUpOrDownTurned("upturned");
			upturnedCorrect = true;
			cout << "UPTURNED A CARD FROM PILE" << endl;
			showBoard();
			cout << "END OF UPTURNED A CARD FROM PILE" << endl;
		}
	}
	else
	{
		cout << "END OF UPTURNED A CARD FROM PILE - NO MORE CARDS" << endl;
		upturnedCorrect = true;
	}
	return upturnedCorrect;
}

vector<CardInBoard>&
KlondiqueBoard::getWastePile()
{
	return wastePile;
}
vector<CardInBoard>&
KlondiqueBoard::getStock()
{
	return stock;
}

vector<CardInBoard>&
KlondiqueBoard::getPile1()
{
	return pile1;
}

vector<CardInBoard>&
KlondiqueBoard::getPile2()
{
	return pile2;
}

vector<CardInBoard>&
KlondiqueBoard::getPile3()
{
	return pile3;
}

vector<CardInBoard>&
KlondiqueBoard::getPile4()
{
	return pile4;
}

vector<CardInBoard>&
KlondiqueBoard::getPile5()
{
	return pile5;
}

vector<CardInBoard>&
KlondiqueBoard::getPile6()
{
	return pile6;
}

vector<CardInBoard>&
KlondiqueBoard::getPile7()
{
	return pile7;
}


vector<CardInBoard>&
KlondiqueBoard::getFoundationHeart()
{
	return foundationHeart;
}

vector<CardInBoard>&
KlondiqueBoard::getFoundationSpade()
{
	return foundationSpade;
}

vector<CardInBoard>&
KlondiqueBoard::getFoundationClub()
{
	return foundationClub;
}

vector<CardInBoard>&
KlondiqueBoard::getFoundationDiamond()
{
	return foundationDiamond;
}

void
KlondiqueBoard::showBoard()
{
	//Print all the Cards in the board (maximum 52)
    cout << "== BOARD ==" << endl;

	// 1) Stock
    cout << "== STOCK ==" << endl;
    if (stock.empty())
    {
    	cout << "== EMPTY ==" << endl;
    }
    else
    {
    	for(vector<CardInBoard>::iterator it = stock.begin(); it != stock.end(); it++)
		{
		   cout << "Card in stock -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
    }


	// 2) Waste Pile
    cout << "== WASTE PILE ==" << endl;
	if (wastePile.empty())
	{
		cout << "== EMPTY ==" << endl;
	}
	else
	{
		for(vector<CardInBoard>::iterator it = wastePile.begin(); it != wastePile.end(); it++)
		{
		   cout << "Card in waste pile -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
	}

	// 3) Foundation Heart (Only Hearts and in order from Ace to King)
	cout << "== FOUNDATION HEART ==" << endl;
	if (foundationHeart.empty())
	{
		cout << "== EMPTY ==" << endl;
	}
	else
	{
		for(vector<CardInBoard>::iterator it = foundationHeart.begin(); it != foundationHeart.end(); it++)
		{
		   cout << "Card in foundation Heart -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
	}

	// 4) Foundation Spade (Only Spades and in order from Ace to King)
	cout << "== FOUNDATION SPADE ==" << endl;
	if (foundationSpade.empty())
	{
		cout << "== EMPTY ==" << endl;
	}
	else
	{
		for(vector<CardInBoard>::iterator it = foundationSpade.begin(); it != foundationSpade.end(); it++)
		{
		   cout << "Card in foundation Spade -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
	}

	// 5) Foundation Club (Only Clubs and in order from Ace to King)
	cout << "== FOUNDATION CLUB ==" << endl;
	if (foundationClub.empty())
	{
		cout << "== EMPTY ==" << endl;
	}
	else
	{
		for(vector<CardInBoard>::iterator it = foundationClub.begin(); it != foundationClub.end(); it++)
		{
		   cout << "Card in foundation Club -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
	}

	// 6) Foundation Diamond (Only Diamonds and in order from Ace to King)
	cout << "== FOUNDATION DIAMOND ==" << endl;
	if (foundationDiamond.empty())
	{
		cout << "== EMPTY ==" << endl;
	}
	else
	{
		for(vector<CardInBoard>::iterator it = foundationDiamond.begin(); it != foundationDiamond.end(); it++)
		{
		   cout << "Card in foundation Diamond -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
	}

	// 7) Pile 1 (maximum 13 Cards, no downturned)
	cout << "== PILE 1 ==" << endl;
	if (pile1.empty())
	{
		cout << "== EMPTY ==" << endl;
	}
	else
	{
		for(vector<CardInBoard>::iterator it = pile1.begin(); it != pile1.end(); it++)
		{
		   cout << "Card in Pile 1 -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
	}

	// 8) Pile 2 (maximum 14 Cards, 1 possible downturned)
	cout << "== PILE 2 ==" << endl;
	if (pile2.empty())
	{
		cout << "== EMPTY ==" << endl;
	}
	else
	{
		for(vector<CardInBoard>::iterator it = pile2.begin(); it != pile2.end(); it++)
		{
		   cout << "Card in Pile 2 -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
	}

	// 9) Pile 3 (maximum 15 Cards, 2 possible downturned)
	cout << "== PILE 3 ==" << endl;
	if (pile3.empty())
	{
		cout << "== EMPTY ==" << endl;
	}
	else
	{
		for(vector<CardInBoard>::iterator it = pile3.begin(); it != pile3.end(); it++)
		{
		   cout << "Card in Pile 3 -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
	}

	// 10) Pile 4 (maximum 16 Cards, 3 possible downturned)
	cout << "== PILE 4 ==" << endl;
	if (pile4.empty())
	{
		cout << "== EMPTY ==" << endl;
	}
	else
	{
		for(vector<CardInBoard>::iterator it = pile4.begin(); it != pile4.end(); it++)
		{
		   cout << "Card in Pile 4 -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
	}

	// 11) Pile 5 (maximum 17 Cards, 4 possible downturned)
	cout << "== PILE 5 ==" << endl;
	if (pile5.empty())
	{
		cout << "== EMPTY ==" << endl;
	}
	else
	{
		for(vector<CardInBoard>::iterator it = pile5.begin(); it != pile5.end(); it++)
		{
		   cout << "Card in Pile 5 -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
	}

	// 12) Pile 6 (maximum 18 Cards, 5 possible downturned)
	cout << "== PILE 6 ==" << endl;
	if (pile6.empty())
	{
		cout << "== EMPTY ==" << endl;
	}
	else
	{
		for(vector<CardInBoard>::iterator it = pile6.begin(); it != pile6.end(); it++)
		{
		   cout << "Card in Pile 6 -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
	}

	// 13) Pile 7 (maximum 19 Cards, 6 possible downturned)
	cout << "== PILE 7 ==" << endl;
	if (pile7.empty())
	{
		cout << "== EMPTY ==" << endl;
	}
	else
	{
		for(vector<CardInBoard>::iterator it = pile7.begin(); it != pile7.end(); it++)
		{
		   cout << "Card in Pile 7 -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;
		}
	}

	cout << "== END BOARD ==" << endl;
}

