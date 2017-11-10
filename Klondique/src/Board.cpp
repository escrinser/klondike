/*
 * KlondiqueBoard.cpp
 *
 *  Created on: 3 oct. 2017
 *      Author: Ana
 */

#include "Board.h"

#include "Suit.h"
#include "Card.h"
#include "Deck.h"
#include "CardInBoard.h"

Board::Board() {
}

Board::~Board() {
}

Board::Board(shared_ptr<Deck> theDeck)
{
	deck = theDeck;
}

void
Board::initBoard()
{
	// stock
	//vector<shared_ptr<Card>> initialDeck = deck->getDeck();


	//for(vector<shared_ptr<Card>>::iterator it = initialDeck.begin(); it != initialDeck.end(); it++)
	for(vector<shared_ptr<Card>>::iterator it = deck->getDeck().begin(); it != deck->getDeck().end(); it++)
	{
	   stock.push_back(shared_ptr<CardInBoard>(new CardInBoard((*it), TurnedEnum::DOWN)));
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
	vector<shared_ptr<Card>> initialDeck = deck->shuffle();
	// upturnedDeck empty

	// Foundation Hearts empty
	// Foundation Spades empty
	// Foundation Clubs empty
	// Foundation Diamonds empty
	for (int i = 0; i < 4; i++)
	{
		vector<shared_ptr<CardInBoard>> temp;

		foundations.push_back(temp);
	}

	// Colocate cards
	for (int i = 1; i < 8; i++) //TODO: Seven piles
	{
		vector<shared_ptr<CardInBoard>> temp; // create an array, don't work directly on buff yet.
		for(int j = 1; j < 8; j++)
		{
			if (j!=i)
			{
				temp.push_back(shared_ptr<CardInBoard>(new CardInBoard (initialDeck.back(), TurnedEnum::DOWN)));
				//cout << "Before Downturned: " << initialDeck.size() << endl;
				initialDeck.pop_back();
				//cout << "After Downturned. Pile = " << i <<": "<< initialDeck.size() << endl;
			}
			else if (j==i)
			{
				temp.push_back(shared_ptr<CardInBoard>(new CardInBoard (initialDeck.back(), TurnedEnum::UP)));
				//cout << "Before Upturned: " << initialDeck.size() << endl;
				initialDeck.pop_back();
				//cout << "After Upturned. Pile = " << i <<": "<< initialDeck.size() << endl;
				break;
			}
		}
		piles.push_back(temp); // Store the array in the buffer
	}

	//cout << "Stock number of cards: "<< initialDeck.size() << endl;
	for(vector<shared_ptr<Card>>::iterator it = initialDeck.begin(); it != initialDeck.end(); it++)
	{
	   stock.push_back(shared_ptr<CardInBoard>(new CardInBoard((*it), TurnedEnum::DOWN)));
	}

	cout << "INIT PLAYING BOARD" << endl;
	//showBoard();
	//cout << "END OF INIT PLAYING BOARD" << endl;
}

int
Board::deal()
{
	if (!stock.empty())
	{
		wastePile.push_back(stock.back());
		(wastePile.back())->setUpOrDownTurned(TurnedEnum::UP);
		stock.pop_back();
		cout << "DEAL A CARD" << endl;
	}
	else
	{
		cout << "There is no cards in stock - Put them in Stock again" << endl;

		while (!wastePile.empty())
		{
			stock.push_back(wastePile.back());
			(stock.back())->setUpOrDownTurned(TurnedEnum::DOWN);
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

	//Move a king to a empty Pile (other card is not allowed)
	if (piles[thePileDestinationNumber - 1].empty())
	{
		cout << "ONLY A KING IS ALLOW FROM PILE TO EMPTY PILE" << endl;
		if (theCardOriginNumber == 0) //TODO: Magic
		{
			if (piles[thePileOriginNumber - 1].back()->getCard()->getNumber()==13)
			{
				// Movement
				piles[thePileDestinationNumber - 1].push_back(piles[thePileOriginNumber - 1].back());
				piles[thePileOriginNumber - 1].pop_back();
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
			vector<shared_ptr<CardInBoard>> pileOrigin2 = piles[thePileOriginNumber - 1];
			vector<shared_ptr<CardInBoard>> pileOriginReverse;
			cout << "Pile Origin size: " << piles[thePileOriginNumber - 1].size() << endl;
			do
			{
				if (pileOrigin2.back()->getUpOrDownTurned() == TurnedEnum::UP &&
								pileOrigin2.back()->getCard()->getNumber() == theCardOriginNumber)
				{
					cout << "I found the King" << endl;
					cout << "Pile Origin size after found the card: " << pileOrigin2.size() << endl;
					if (pileOrigin2.back()->getCard()->getNumber() == 13)
					{
						// Movement
						// Put all the cards in the Pile Destination
						pileOriginReverse.push_back(pileOrigin2.back());
						pileOrigin2.pop_back();

						// Delete from the Pile Origin all the cards
						do
						{
							// Put in the destination all the cards
							piles[thePileDestinationNumber - 1].push_back(pileOriginReverse.back());
							pileOriginReverse.pop_back();
							piles[thePileOriginNumber - 1].pop_back();
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
			if ((piles[thePileOriginNumber - 1].back()->getCard()->getNumber() ==
						(piles[thePileDestinationNumber - 1].back()->getCard()->getNumber() - 1)) &&
							(piles[thePileOriginNumber - 1].back()->getCard()->getSuit()->getColor() !=
								(piles[thePileDestinationNumber - 1].back()->getCard()->getSuit()->getColor())))
			{
				// Movement
				piles[thePileDestinationNumber - 1].push_back(piles[thePileOriginNumber - 1].back());
				piles[thePileOriginNumber - 1].pop_back();
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
			vector<shared_ptr<CardInBoard>> pileOrigin2 = piles[thePileOriginNumber - 1];
			vector<shared_ptr<CardInBoard>> pileOriginReverse;
			cout << "Pile Origin size: " << piles[thePileOriginNumber - 1].size() << endl;
			do
			{
				if (pileOrigin2.back()->getUpOrDownTurned() == TurnedEnum::UP &&
								pileOrigin2.back()->getCard()->getNumber() == theCardOriginNumber)
				{
					cout << "I found the card" << endl;
					cout << "Pile Origin size after found the card: " << pileOrigin2.size() << endl;
					if ((pileOrigin2.back()->getCard()->getNumber() ==
										(piles[thePileDestinationNumber - 1].back()->getCard()->getNumber() - 1)) &&
											(pileOrigin2.back()->getCard()->getSuit()->getColor() !=
												(piles[thePileDestinationNumber - 1].back()->getCard()->getSuit()->getColor())))
					{
						// Movement
						// Put all the cards in the Pile Destination
						pileOriginReverse.push_back(pileOrigin2.back());
						pileOrigin2.pop_back();

						// Delete from the Pile Origin all the cards
						do
						{
							// Put in the destination all the cards
							piles[thePileDestinationNumber - 1].push_back(pileOriginReverse.back());
							pileOriginReverse.pop_back();
							piles[thePileOriginNumber - 1].pop_back();
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
		upturnCard = upturnCardInPile(piles[thePileOriginNumber - 1]);
	}
	return movementCorrect && upturnCard;
}

bool
Board::moveBetweenPileAndFoundation(int thePileOriginNumber)
{
	//return 0 -> no movement (not possible, different suit or not the next number)
	bool movementCorrect = false;

	int foundationNumber = giveMeTheFoundationFromCard(piles[thePileOriginNumber - 1]);

	if(foundations[foundationNumber].empty())
	{
		if (piles[thePileOriginNumber - 1].back()->getCard()->getNumber() == 1)
		{
			// Movement
			foundations[foundationNumber].push_back(piles[thePileOriginNumber - 1].back());
			piles[thePileOriginNumber - 1].pop_back();
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
		if (piles[thePileOriginNumber - 1].back()->getCard()->getNumber() ==
				(foundations[foundationNumber].back()->getCard()->getNumber() + 1))
		{
			// Movement
			foundations[foundationNumber].push_back(piles[thePileOriginNumber - 1].back());
			piles[thePileOriginNumber - 1].pop_back();
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
		upturnCard = upturnCardInPile(piles[thePileOriginNumber - 1]);
	}
	return movementCorrect && upturnCard;
}

bool
Board::moveBetweenWastePileAndPile(int thePileDestinationNumber)
{
	//return 0 -> no movement (not possible, same color or not the next number)
	bool movementCorrect = false;

	if (!wastePile.empty())
	{
		//Move a king to a empty Pile (other card is not allowed)
		if (piles[thePileDestinationNumber - 1].empty())
		{
			cout << "ONLY A KING IS ALLOW FROM PILE TO EMPTY PILE" << endl;
			if (wastePile.back()->getCard()->getNumber()==13)
			{
				// Movement
				piles[thePileDestinationNumber - 1].push_back(wastePile.back());
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
			if ((wastePile.back()->getCard()->getNumber() ==
							(piles[thePileDestinationNumber - 1].back()->getCard()->getNumber() - 1)) &&
								(wastePile.back()->getCard()->getSuit()->getColor() !=
									(piles[thePileDestinationNumber - 1].back()->getCard()->getSuit()->getColor())))
			{
				// Movement
				piles[thePileDestinationNumber - 1].push_back(wastePile.back());
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

	int foundationNumber = giveMeTheFoundationFromCard(wastePile);

	if(foundations[foundationNumber].empty())
	{
		if (wastePile.back()->getCard()->getNumber() == 1) // Check if it is an Ace
		{
			// Movement
			foundations[foundationNumber].push_back(wastePile.back());
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
		if (wastePile.back()->getCard()->getNumber() ==
				(foundations[foundationNumber].back()->getCard()->getNumber() + 1))
		{
			// Movement
			foundations[foundationNumber].push_back(wastePile.back());
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

//TODO: Try to return SuitType
int
Board::giveMeTheFoundationFromCard(vector<shared_ptr<CardInBoard>> theOrigin)
{
	SuitType suit = theOrigin.back()->getCard()->getSuit()->getSuit();
	switch(suit)
	{
	    case SuitType::HEARTS  :
	    	return 0;
	    	break;
	    case SuitType::CLUB  :
	    	return 1;
	    	break;
	    case SuitType::SPADE  :
	    	return 2;
	    	break;
	    case SuitType::DIAMOND  :
	    	return 3;
	    	break;
	}
	return 0;
}

bool
Board::upturnCardInPile(vector<shared_ptr<CardInBoard>> thePile)
{
	bool upturnedCorrect = false;

	if(!thePile.empty())
	{
		if ((thePile.back())->getUpOrDownTurned() == TurnedEnum::DOWN)
		{
			thePile.back()->setUpOrDownTurned(TurnedEnum::UP);
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

	for (unsigned int i=0 ; i < foundations.size(); i++)
	{
		string foundationName;
		if (i==0)
		{
			foundationName = "HEART";
		}
		else if (i==1)
		{
			foundationName = "SPADE";
		}
		else if (i==2)
		{
			foundationName = "CLUB";
		}
		else if (i==3)
		{
			foundationName = "DIAMOND";
		}
		cout << "== FOUNDATION " << foundationName  << "==" << endl;
		showElement(foundations[i]);
	}

	for (unsigned int i=0 ; i < piles.size(); i++)
	{
		cout << "== PILE " << i+1  << "==" << endl;
		showElement(piles[i]);
	}

	cout << "== END BOARD ==" << endl;
}

void
Board::showElement(vector<shared_ptr<CardInBoard>> theElement)
{
    if (theElement.empty())
    {
    	cout << "== EMPTY ==" << endl;
    }
    else
    {
    	cout << "Cards:";
    	for(vector<shared_ptr<CardInBoard>>::iterator it = theElement.begin(); it != theElement.end(); it++)
		{
    		//Only show cards upturned, X for downturned
    		cout << " ";
    		if ((*it)->getUpOrDownTurned() == TurnedEnum::DOWN)
    		{
    			cout << "X";
    		}
    		else if ((*it)->getUpOrDownTurned() == TurnedEnum::UP)
    		{
    			//cout << ((*it)->getCard())->getNumber() << (*it)->getCard()->getSuit()->getSuit() << (*it)->getCard()->getSuit()->getColor();

    			cout << ((*it)->getCard())->getNumber() << (*it)->getCard()->getSuit()->toString((*it)->getCard()->getSuit()->getSuit());
    		}
    		else
    		{
    			cout << "Impossible situation." << endl;
    		}
		}
    }
    cout << endl;
}

vector<vector<shared_ptr<CardInBoard>>>
Board::getFoundations()
{
	return foundations;
}

bool
Board::hasWon()
{
	if (!foundations[0].empty()
			&& !foundations[1].empty()
				&& !foundations[2].empty()
					&& !foundations[3].empty())
	{
		if (((foundations[0].back()->getCard())->getNumber() == 13)
				&& (foundations[1].back()->getCard()->getNumber() == 13)
					 && (foundations[2].back()->getCard()->getNumber() == 13)
						&& (foundations[3].back()->getCard()->getNumber() == 13))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void
Board::clear()
{
	stock.clear();
	wastePile.clear();
	foundations.clear();
	piles.clear();
}
