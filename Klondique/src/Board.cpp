/*
 * KlondiqueBoard.cpp
 *
 *  Created on: 3 oct. 2017
 *      Author: Ana
 */

#include "Board.h"

#include "CardInBoard.h"

Board::Board() {
}

Board::~Board() {
}

Board::Board(Deck theDeck)
{
	deck = theDeck;
}

Board::Board(Deck theDeck, vector<Pile> thePiles, vector<Foundation> theFoundations)
{
	deck = theDeck;
	piles = thePiles;
	foundations = theFoundations;
}

void
Board::initBoard()
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
Board::startPlayingBoard()
{
	vector<Card> initialDeck = deck.shuffle();
	// upturnedDeck empty

	// Foundation Hearts empty
	// Foundation Spades empty
	// Foundation Clubs empty
	// Foundation Diamonds empty

	// Pile1
	pile1.push_back(CardInBoard (initialDeck.back(), "upturned"));
	//cout << "Before Pile 1: " << initialDeck.size() << endl;
	initialDeck.pop_back();
	//cout << "After Pile 1: "<< initialDeck.size() << endl;

	// Pile2
	pile2.push_back(CardInBoard (initialDeck.back(), "downturned"));
	initialDeck.pop_back();
	pile2.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 2: "<< initialDeck.size() << endl;

	// Pile3
	for (int x=0; x<2; x++)
	{
		pile3.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile3.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 3: "<< initialDeck.size() << endl;

	// Pile4
	for (int x=0; x<3; x++)
	{
		pile4.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile4.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 4: "<< initialDeck.size() << endl;

	// Pile5
	for (int x=0; x<4; x++)
	{
		pile5.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile5.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 5: "<< initialDeck.size() << endl;

	// Pile6
	for (int x=0; x<5; x++)
	{
		pile6.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile6.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 6: "<< initialDeck.size() << endl;

	// Pile7
	for (int x=0; x<6; x++)
	{
		pile7.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile7.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 7: "<< initialDeck.size() << endl;

	// stock
	//cout << "Stock number of cards: "<< initialDeck.size() << endl;
	for(vector<Card>::iterator it = initialDeck.begin(); it != initialDeck.end(); it++)
	{
	   stock.push_back(CardInBoard ((*it), "downturned"));
	}

	cout << "INIT PLAYING BOARD" << endl;
	showBoard();
	cout << "END OF INIT PLAYING BOARD" << endl;
}

void
Board::startPlayingBoard2()
{
	vector<Card> initialDeck = deck.shuffle();
	// upturnedDeck empty

	// Foundation Hearts empty
	cout << "Foundations size: " << foundations.size() << endl;
	//cout << foundations.back().getSuit() << endl;
	// Foundation Spades empty
	// Foundation Clubs empty
	// Foundation Diamonds empty

	// Pile1
	cout << "Piles size: " << piles.size() << endl;
	cout << piles.back().getNumber() << endl;

	for (vector<Pile>::iterator it = piles.begin(); it != piles.end(); it++)
	{
		cout << "Pile number: " << (*it).number << endl;
	}

	cout << "Pile 2: " << piles.at(1).getNumber() << endl;

	pile1.push_back(CardInBoard (initialDeck.back(), "upturned"));
	//cout << "Before Pile 1: " << initialDeck.size() << endl;
	initialDeck.pop_back();
	//cout << "After Pile 1: "<< initialDeck.size() << endl;
	piles.at(0).addCards(pile1);

	// Pile2
	pile2.push_back(CardInBoard (initialDeck.back(), "downturned"));
	initialDeck.pop_back();
	pile2.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 2: "<< initialDeck.size() << endl;
	piles.at(1).addCards(pile2);

	// Pile3
	for (int x=0; x<2; x++)
	{
		pile3.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile3.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 3: "<< initialDeck.size() << endl;
	piles.at(2).addCards(pile3);

	// Pile4
	for (int x=0; x<3; x++)
	{
		pile4.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile4.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 4: "<< initialDeck.size() << endl;
	piles.at(3).addCards(pile4);

	// Pile5
	for (int x=0; x<4; x++)
	{
		pile5.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile5.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 5: "<< initialDeck.size() << endl;
	piles.at(4).addCards(pile5);

	// Pile6
	for (int x=0; x<5; x++)
	{
		pile6.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile6.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 6: "<< initialDeck.size() << endl;
	piles.at(5).addCards(pile6);

	// Pile7
	for (int x=0; x<6; x++)
	{
		pile7.push_back(CardInBoard (initialDeck.back(), "downturned"));
		initialDeck.pop_back();
	}
	pile7.push_back(CardInBoard (initialDeck.back(), "upturned"));
	initialDeck.pop_back();
	//cout << "After Pile 7: "<< initialDeck.size() << endl;
	piles.at(6).addCards(pile7);

	// stock
	//cout << "Stock number of cards: "<< initialDeck.size() << endl;
	for(vector<Card>::iterator it = initialDeck.begin(); it != initialDeck.end(); it++)
	{
	   stock.push_back(CardInBoard ((*it), "downturned"));
	}

	cout << "INIT PLAYING BOARD" << endl;
	showBoard();
	cout << "END OF INIT PLAYING BOARD" << endl;
}

int
Board::deal()
{
	if (!stock.empty())
	{
		wastePile.push_back(stock.back());
		wastePile.back().setUpOrDownTurned("upturned");
		stock.pop_back();
		cout << "DEAL A CARD" << endl;
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

bool
Board::moveBetweenPiles(int thePileOriginNumber,
	     	 	 	    int thePileDestinationNumber,
					    int theCardOriginNumber)
{
	//return 0 -> no movement (not possible, no same pile, same color or not the next number)
	bool movementCorrect = false;

	vector<CardInBoard>& pileOrigin = giveMeThePile(thePileOriginNumber);
	vector<CardInBoard>& pileDestination = giveMeThePile(thePileDestinationNumber);

	//Move a king to a empty Pile (other card is not allowed)
	if (pileDestination.empty())
	{
		cout << "ONLY A KING IS ALLOW FROM PILE TO EMPTY PILE" << endl;
		if (theCardOriginNumber == 0) //TODO: Magic
		{
			if (pileOrigin.back().getCard().getNumber()==13)
			{
				// Movement
				pileDestination.push_back(pileOrigin.back());
				pileOrigin.pop_back();
				movementCorrect = true;
				cout << "MOVE A KING FROM PILE TO EMPTY PILE" << endl;
			}
			else
			{
				cout << "Not possible movement" << endl;
			}
		}
		else // Movement of more than 1 card...
		{
			vector<CardInBoard> pileOrigin2 = pileOrigin;
			vector<CardInBoard> pileOriginReverse;
			cout << "Pile Origin size: " << pileOrigin.size() << endl;
			do
			{
				if (pileOrigin2.back().getUpOrDownTurned() == "upturned" &&
								pileOrigin2.back().getCard().getNumber() == theCardOriginNumber)
				{
					cout << "I found the King" << endl;
					cout << "Pile Origin size after found the card: " << pileOrigin2.size() << endl;
					if (pileOrigin2.back().getCard().getNumber() == 13)
					{
						// Movement
						// Put all the cards in the Pile Destination
						pileOriginReverse.push_back(pileOrigin2.back());
						pileOrigin2.pop_back();

						// Delete from the Pile Origin all the cards
						do
						{
							// Put in the destination all the cards
							pileDestination.push_back(pileOriginReverse.back());
							pileOriginReverse.pop_back();
							pileOrigin.pop_back();
						} while (pileOriginReverse.size() != 0);

						movementCorrect = true;
						cout << "MOVE SEVERAL CARDS FROM PILE TO PILE" << endl;
					}
					else
					{
						cout << "Not possible movement" << endl;
					}
					break;
				}
				else
				{
					cout << "This is not the card" << endl;
					pileOriginReverse.push_back(pileOrigin2.back());
					pileOrigin2.pop_back();
				}
			}
			while  (pileOrigin2.size() != 0);
		}

	}
	else
	{
		if (theCardOriginNumber == 0) //TODO: Magic
		{
			if ((pileOrigin.back().getCard().getNumber() ==
						(pileDestination.back().getCard().getNumber() - 1)) &&
							(pileOrigin.back().getCard().getSuit().getColor() !=
								(pileDestination.back().getCard().getSuit().getColor())))
			{
				// Movement
				pileDestination.push_back(pileOrigin.back());
				pileOrigin.pop_back();
				movementCorrect = true;
				cout << "MOVE A CARD FROM PILE TO PILE" << endl;
			}
			else
			{
				cout << "Not possible movement" << endl;
			}
		}
		else // Movement of more than 1 card...
		{
			vector<CardInBoard> pileOrigin2 = pileOrigin;
			vector<CardInBoard> pileOriginReverse;
			cout << "Pile Origin size: " << pileOrigin.size() << endl;
			do
			{
				if (pileOrigin2.back().getUpOrDownTurned() == "upturned" &&
								pileOrigin2.back().getCard().getNumber() == theCardOriginNumber)
				{
					cout << "I found the card" << endl;
					cout << "Pile Origin size after found the card: " << pileOrigin2.size() << endl;
					if ((pileOrigin2.back().getCard().getNumber() ==
										(pileDestination.back().getCard().getNumber() - 1)) &&
											(pileOrigin2.back().getCard().getSuit().getColor() !=
												(pileDestination.back().getCard().getSuit().getColor())))
					{
						// Movement
						// Put all the cards in the Pile Destination
						pileOriginReverse.push_back(pileOrigin2.back());
						pileOrigin2.pop_back();

						// Delete from the Pile Origin all the cards
						do
						{
							// Put in the destination all the cards
							pileDestination.push_back(pileOriginReverse.back());
							pileOriginReverse.pop_back();
							pileOrigin.pop_back();
						} while (pileOriginReverse.size() != 0);

						movementCorrect = true;
						cout << "MOVE SEVERAL CARDS FROM PILE TO PILE" << endl;
					}
					else
					{
						cout << "Not possible movement" << endl;
					}
					break;
				}
				else
				{
					cout << "This is not the card" << endl;
					pileOriginReverse.push_back(pileOrigin2.back());
					pileOrigin2.pop_back();
				}
			}
			while  (pileOrigin2.size() != 0);
		}
	}

	bool upturnCard = false;
	if (movementCorrect)
	{
		upturnCard = upturnCardInPile(pileOrigin);
	}
	return movementCorrect && upturnCard;
}

bool
Board::moveBetweenPileAndFoundation(int thePileOriginNumber)
{
	//return 0 -> no movement (not possible, different suit or not the next number)
	bool movementCorrect = false;

	vector<CardInBoard>& pileOrigin = giveMeThePile(thePileOriginNumber); //TODO: Preguntar a Jose que es esto que estoy haciendo (copias?)
	vector<CardInBoard>& foundationDestination = giveMeTheFoundationFromCard(pileOrigin);

	if(foundationDestination.empty())
	{
		if (pileOrigin.back().getCard().getNumber() == 1)
		{
			// Movement
			foundationDestination.push_back(pileOrigin.back());
			pileOrigin.pop_back();
			movementCorrect = true;
			cout << "MOVE A CARD FROM PILE TO FOUNDATION" << endl;
		}
		else
		{
			cout << "Not possible movement, it is not an Ace" << endl;
		}
	}
	else
	{
		if (pileOrigin.back().getCard().getNumber() ==
				(foundationDestination.back().getCard().getNumber() + 1))
		{
			// Movement
			foundationDestination.push_back(pileOrigin.back());
			pileOrigin.pop_back();
			movementCorrect = true;
			cout << "MOVE A CARD FROM PILE TO FOUNDATION" << endl;
		}
		else
		{
			cout << "Not possible movement" << endl;
		}
	}

	bool upturnCard = false;
	if (movementCorrect)
	{
		upturnCard = upturnCardInPile(pileOrigin);
	}
	return movementCorrect && upturnCard;
}

bool
Board::moveBetweenWastePileAndPile(int thePileDestinationNumber)
{
	//return 0 -> no movement (not possible, same color or not the next number)
	bool movementCorrect = false;

	vector<CardInBoard>& pileDestination = giveMeThePile(thePileDestinationNumber);
	if (!wastePile.empty())
	{
		//Move a king to a empty Pile (other card is not allowed)
		if (pileDestination.empty())
		{
			cout << "ONLY A KING IS ALLOW FROM PILE TO EMPTY PILE" << endl;
			if (wastePile.back().getCard().getNumber()==13)
			{
				// Movement
				pileDestination.push_back(wastePile.back());
				wastePile.pop_back();
				movementCorrect = true;
				cout << "MOVE A KING FROM PILE TO EMPTY PILE" << endl;
			}
			else
			{
				cout << "Not possible movement" << endl;
			}
		}
		else
		{
			if ((wastePile.back().getCard().getNumber() ==
							(pileDestination.back().getCard().getNumber() - 1)) &&
								(wastePile.back().getCard().getSuit().getColor() !=
									(pileDestination.back().getCard().getSuit().getColor())))
			{
				// Movement
				pileDestination.push_back(wastePile.back());
				wastePile.pop_back();
				movementCorrect = true;
				cout << "MOVE A CARD FROM WASTE PILE TO PILE" << endl;
			}
			else
			{
				cout << "Not possible movement" << endl;
			}
		}
	}
	else
	{
		cout << "Not possible movement - Waste Pile Empty" << endl;
	}
	return movementCorrect;
}

bool
Board::moveBetweenWastePileAndFoundation()
{
	//return 0 -> no movement (not possible, different suit or not the next number)
	bool movementCorrect = false;

	vector<CardInBoard>& foundationDestination = giveMeTheFoundationFromCard(wastePile);

	if(foundationDestination.empty())
	{
		if (wastePile.back().getCard().getNumber() == 1) // Check if it is an Ace
		{
			// Movement
			foundationDestination.push_back(wastePile.back());
			wastePile.pop_back();
			movementCorrect = true;
			cout << "MOVE A CARD FROM WASTE PILE TO FOUNDATION" << endl;
		}
		else
		{
			cout << "Not possible movement, the card is not an Ace" << endl;
		}
	}
	else
	{
		if (wastePile.back().getCard().getNumber() ==
				(foundationDestination.back().getCard().getNumber() + 1))
		{
			// Movement
			foundationDestination.push_back(wastePile.back());
			wastePile.pop_back();
			movementCorrect = true;
			cout << "MOVE A CARD FROM PILE TO FOUNDATION" << endl;
		}
		else
		{
			cout << "Not possible movement" << endl;
		}
	}
	return movementCorrect;
}

vector<CardInBoard>&
Board::giveMeThePile(int thePileDestinationNumber)
{
	switch (thePileDestinationNumber)
	{
	   case 1:
		   return getPile1();
		   //break;
	   case 2:
		   return getPile2();
		   //break;
	   case 3:
		   return getPile3();
		   //break;
	   case 4:
		   return getPile4();
		   //break;
	   case 5:
		   return getPile5();
		   //break;
	   case 6:
		   return getPile6();
		   //break;
	   case 7:
		   return getPile7();
		   //break;
	   /*default:
		   cout << "Not a Valid Pile Number.\n";
		   break;*/
	}
	//TODO: this return is very bad!!!
	return getPile1();
}
//TODO: Cards to Foundations directly (no mean to say the suit)

vector<CardInBoard>&
Board::giveMeTheFoundation(int theFoundationDestinationNumber)
{
	switch (theFoundationDestinationNumber)
	{
	   case 1:
		   return getFoundationHeart();
		   //break;
	   case 2:
		   return getFoundationSpade();
		   //break;
	   case 3:
		   return getFoundationClub();
		   //break;
	   case 4:
		   return getFoundationDiamond();
		   //break;
	   /*default:
		   cout << "Not a Valid Pile Number.\n";
		   break;*/
	}
	//TODO: this return is very bad!!!
	return getFoundationHeart();
}

vector<CardInBoard>&
Board::giveMeTheFoundationFromCard(vector<CardInBoard> theOrigin)
{
	string suit = theOrigin.back().getCard().getSuit().getSuit();
	if (suit == "heart")
	{
		return getFoundationHeart();
	}
	else if (suit == "spade")
	{
		return getFoundationSpade();
	}
	else if (suit == "club")
	{
		return getFoundationClub();
	}
	else if (suit == "diamond")
	{
		return getFoundationDiamond();
	}
	else
	{
		//TODO: not possible situation but bad code...
		return getFoundationDiamond();
	}
}

bool
Board::upturnCardInPile(vector<CardInBoard>& thePile)
{
	bool upturnedCorrect = false;

	if(!thePile.empty())
	{
		if (thePile.back().getUpOrDownTurned() == "downturned")
		{
			thePile.back().setUpOrDownTurned("upturned");
			upturnedCorrect = true;
			cout << "UPTURNED A CARD FROM PILE" << endl;
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
Board::getWastePile()
{
	return wastePile;
}
vector<CardInBoard>&
Board::getStock()
{
	return stock;
}

vector<CardInBoard>&
Board::getPile1()
{
	return pile1;
}

vector<CardInBoard>&
Board::getPile2()
{
	return pile2;
}

vector<CardInBoard>&
Board::getPile3()
{
	return pile3;
}

vector<CardInBoard>&
Board::getPile4()
{
	return pile4;
}

vector<CardInBoard>&
Board::getPile5()
{
	return pile5;
}

vector<CardInBoard>&
Board::getPile6()
{
	return pile6;
}

vector<CardInBoard>&
Board::getPile7()
{
	return pile7;
}


vector<CardInBoard>&
Board::getFoundationHeart()
{
	return foundationHeart;
}

vector<CardInBoard>&
Board::getFoundationSpade()
{
	return foundationSpade;
}

vector<CardInBoard>&
Board::getFoundationClub()
{
	return foundationClub;
}

vector<CardInBoard>&
Board::getFoundationDiamond()
{
	return foundationDiamond;
}

void
Board::showBoard()
{
	//Print all the Cards in the board (maximum 52)
    cout << "== BOARD ==" << endl;

	// 1) Stock
    cout << "== STOCK ==" << endl;
    showElement(stock);

	// 2) Waste Pile
    cout << "== WASTE PILE ==" << endl;
    showElement(wastePile);

	// 3) Foundation Heart (Only Hearts and in order from Ace to King)
	cout << "== FOUNDATION HEART ==" << endl;
	showElement(foundationHeart);

	// 4) Foundation Spade (Only Spades and in order from Ace to King)
	cout << "== FOUNDATION SPADE ==" << endl;
	showElement(foundationSpade);

	// 5) Foundation Club (Only Clubs and in order from Ace to King)
	cout << "== FOUNDATION CLUB ==" << endl;
	showElement(foundationClub);

	// 6) Foundation Diamond (Only Diamonds and in order from Ace to King)
	cout << "== FOUNDATION DIAMOND ==" << endl;
	showElement(foundationDiamond);

	// 7) Pile 1 (maximum 13 Cards, no downturned)
	cout << "== PILE 1 ==" << endl;
	showElement(pile1);

	// 8) Pile 2 (maximum 14 Cards, 1 possible downturned)
	cout << "== PILE 2 ==" << endl;
	showElement(pile2);

	// 9) Pile 3 (maximum 15 Cards, 2 possible downturned)
	cout << "== PILE 3 ==" << endl;
	showElement(pile3);

	// 10) Pile 4 (maximum 16 Cards, 3 possible downturned)
	cout << "== PILE 4 ==" << endl;
	showElement(pile4);

	// 11) Pile 5 (maximum 17 Cards, 4 possible downturned)
	cout << "== PILE 5 ==" << endl;
	showElement(pile5);

	// 12) Pile 6 (maximum 18 Cards, 5 possible downturned)
	cout << "== PILE 6 ==" << endl;
	showElement(pile6);

	// 13) Pile 7 (maximum 19 Cards, 6 possible downturned)
	cout << "== PILE 7 ==" << endl;
	showElement(pile7);

	cout << "== END BOARD ==" << endl;
}

void
Board::showElement(vector<CardInBoard>& theElement)
{
    if (theElement.empty())
    {
    	cout << "== EMPTY ==" << endl;
    }
    else
    {
    	cout << "Cards:";
    	for(vector<CardInBoard>::iterator it = theElement.begin(); it != theElement.end(); it++)
		{
    		//Only show cards upturned, X for downturned
    		cout << " ";
    		if ((*it).getUpOrDownTurned() == "downturned")
    		{
    			cout << "X";
    		}
    		else if ((*it).getUpOrDownTurned() == "upturned")
    		{
    			cout << (*it).getCard().getNumber() << (*it).getCard().getSuit().getSuit() << (*it).getCard().getSuit().getColor();
    		}
    		else
    		{
    			cout << "Impossible situation." << endl;
    		}
		   /*cout << "Card -> number: " << (*it).getCard().getNumber() << ", suit: "
				   << (*it).getCard().getSuit().getSuit() << ", color: " << (*it).getCard().getSuit().getColor()
					   << ", position: " << (*it).getUpOrDownTurned() << endl;*/
		}
    }
    cout << endl;
}

