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
Board::startPlayingBoard()
{
	vector<shared_ptr<Card>> initialDeck = deck->shuffle();
	// upturnedDeck empty

	// Foundation Hearts empty
	// Foundation Spades empty
	// Foundation Clubs empty
	// Foundation Diamonds empty
	for (int i = 0; i < NUMBER_OF_FOUNDATIONS; i++)
	{
		vector<shared_ptr<CardInBoard>> temp;

		foundations.push_back(temp);
	}

	// Colocate cards
	for (int i = 0; i < NUMBER_OF_PILES; i++)
	{
		vector<shared_ptr<CardInBoard>> temp; // create an array, don't work directly on buff yet.
		for(int j = 0; j < NUMBER_OF_PILES; j++)
		{
			if (j!=i)
			{
				temp.push_back(shared_ptr<CardInBoard>(new CardInBoard (initialDeck.back(), TurnedEnum::DOWN)));
				initialDeck.pop_back();
			}
			else if (j==i)
			{
				temp.push_back(shared_ptr<CardInBoard>(new CardInBoard (initialDeck.back(), TurnedEnum::UP)));
				initialDeck.pop_back();
				break;
			}
		}
		piles.push_back(temp); // Store the array in the buffer
	}

	for(vector<shared_ptr<Card>>::iterator it = initialDeck.begin(); it != initialDeck.end(); it++)
	{
	   stock.push_back(shared_ptr<CardInBoard>(new CardInBoard((*it), TurnedEnum::DOWN)));
	}
}

void
Board::deal()
{
	if (!stock.empty())
	{
		wastePile.push_back(stock.back());
		(wastePile.back())->setUpOrDownTurned(TurnedEnum::UP);
		stock.pop_back();
	}
	else
	{
		cout << "There is no cards in stock - Put them in Stock again" << endl;
		if (wastePile.empty())
		{
			cout << "There is no cards in stock - Not even in the waste..." << endl;
		}
		while (!wastePile.empty())
		{
			stock.push_back(wastePile.back());
			(stock.back())->setUpOrDownTurned(TurnedEnum::DOWN);
			wastePile.pop_back();
		}

		cout << "Ready to deal again" << endl;
		deal();
	}
}

void
Board::moveBetweenPiles(int thePileOriginNumber,
	     	 	 	    int thePileDestinationNumber,
					    int theCardOriginNumber)
{
	bool movementCorrect = false;
	if (!piles[thePileOriginNumber - 1].empty())
	{
		if (theCardOriginNumber == 0)
		{
			if (canMoveToPile(piles[thePileOriginNumber - 1].back()->getCard(), thePileDestinationNumber))
			{
				piles[thePileDestinationNumber - 1].push_back(piles[thePileOriginNumber - 1].back());
				piles[thePileOriginNumber - 1].pop_back();
				upturnCardInPile(piles[thePileOriginNumber - 1]);
			}
		}
		else // Move more than one card from pile to pile
		{
			vector<shared_ptr<CardInBoard>> pileOrigin2 = piles[thePileOriginNumber - 1];
			vector<shared_ptr<CardInBoard>> pileOriginReverse;
			cout << "Pile Origin size: " << piles[thePileOriginNumber - 1].size() << endl;
			do
			{
				if (pileOrigin2.back()->getUpOrDownTurned() == TurnedEnum::UP &&
								pileOrigin2.back()->getCard()->getNumber() == theCardOriginNumber)
				{
					if (canMoveToPile(pileOrigin2.back()->getCard(), thePileDestinationNumber))
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

			if (movementCorrect)
			{
				upturnCardInPile(piles[thePileOriginNumber - 1]);
			}
		}
	}
}

void
Board::moveBetweenPileAndFoundation(int thePileOriginNumber)
{
	int foundationNumber;

	if (!piles[thePileOriginNumber - 1].empty())
	{
		foundationNumber = giveMeTheFoundationNumber(piles[thePileOriginNumber - 1].back()->getCard()->getSuit()->getSuit());

		if (canMoveToFoundation(piles[thePileOriginNumber - 1].back()->getCard()->getNumber(), foundationNumber))
		{
			foundations[foundationNumber].push_back(piles[thePileOriginNumber - 1].back());
			piles[thePileOriginNumber - 1].pop_back();
			upturnCardInPile(piles[thePileOriginNumber - 1]);
		}
	}
}

void
Board::moveBetweenWastePileAndPile(int thePileDestinationNumber)
{
	if (!wastePile.empty())
	{
		if (canMoveToPile(wastePile.back()->getCard(), thePileDestinationNumber))
		{
			piles[thePileDestinationNumber - 1].push_back(wastePile.back());
			wastePile.pop_back();
		}
	}
}

void
Board::moveBetweenWastePileAndFoundation()
{
	int foundationNumber;

	if (!wastePile.empty())
	{
		foundationNumber = giveMeTheFoundationNumber(wastePile.back()->getCard()->getSuit()->getSuit());

		if (canMoveToFoundation(wastePile.back()->getCard()->getNumber(), foundationNumber))
		{
			foundations[foundationNumber].push_back(wastePile.back());
			wastePile.pop_back();
		}
	}
}

bool
Board::canMoveToPile(shared_ptr<Card> theCard, int thePileDestinationNumber)
{
	if((piles[thePileDestinationNumber-1].empty() && (theCard->getNumber() == KING))
			|| (((theCard->getNumber()) ==
					(piles[thePileDestinationNumber - 1].back()->getCard()->getNumber() - 1)) &&
						(theCard->getSuit()->getColor() !=
							(piles[thePileDestinationNumber - 1].back()->getCard()->getSuit()->getColor()))))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool
Board::canMoveToFoundation(int theCardNumber, int theFoundationNumber)
{
	if((foundations[theFoundationNumber].empty() && (theCardNumber == ACE))
			|| (theCardNumber ==
					(foundations[theFoundationNumber].back()->getCard()->getNumber() + 1)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int
Board::giveMeTheFoundationNumber(SuitType theSuit)
{
	switch(theSuit)
	{
	    case SuitType::HEART  :
	    	return FOUNDATION_HEART;
	    	break;
	    case SuitType::SPADE  :
	    	return FOUNDATION_SPADE;
	    	break;
	    case SuitType::CLUB  :
	    	return FOUNDATION_CLUB;
	    	break;
	    case SuitType::DIAMOND  :
	    	return FOUNDATION_DIAMOND;
	    	break;
	}
	return 0;
}

void
Board::upturnCardInPile(vector<shared_ptr<CardInBoard>> thePile)
{
	if(!thePile.empty())
	{
		if ((thePile.back())->getUpOrDownTurned() == TurnedEnum::DOWN)
		{
			thePile.back()->setUpOrDownTurned(TurnedEnum::UP);
		}
	}
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
		if (i==FOUNDATION_HEART)
		{
			foundationName = "HEART";
		}
		else if (i==FOUNDATION_SPADE)
		{
			foundationName = "SPADE";
		}
		else if (i==FOUNDATION_CLUB)
		{
			foundationName = "CLUB";
		}
		else if (i==FOUNDATION_DIAMOND)
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

bool
Board::hasWon()
{
	if (!foundations[FOUNDATION_HEART].empty()
			&& !foundations[FOUNDATION_SPADE].empty()
				&& !foundations[FOUNDATION_CLUB].empty()
					&& !foundations[FOUNDATION_DIAMOND].empty())
	{
		if (((foundations[FOUNDATION_HEART].back()->getCard())->getNumber() == KING)
				&& (foundations[FOUNDATION_SPADE].back()->getCard()->getNumber() == KING)
					 && (foundations[FOUNDATION_CLUB].back()->getCard()->getNumber() == KING)
						&& (foundations[FOUNDATION_DIAMOND].back()->getCard()->getNumber() == KING))
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
