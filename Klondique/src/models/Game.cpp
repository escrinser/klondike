#include "Game.h"
#include "Board.h"

Game::Game() {
	state = State::INITIAL;

	shared_ptr<Deck> deck (new Deck());
	vector<shared_ptr<Suit>> allSuites;

	allSuites.push_back(shared_ptr<Suit>(new Suit(Suit::SuitType::HEART, Suit::SuitColor::RED, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(Suit::SuitType::SPADE, Suit::SuitColor::BLACK, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(Suit::SuitType::CLUB, Suit::SuitColor::BLACK, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(Suit::SuitType::DIAMOND, Suit::SuitColor::RED, NUMBER_OF_CARDS)));

	deck->loadDeck(allSuites);
	board = shared_ptr<Board>(new Board(deck));

	//mementoRegistry = new MementoRegistry(this);
}

Game::~Game() {
}

void
Game::startPlayingBoard()
{
	board->startPlayingBoard();
	registry();
	//mementoRegistry->SaveState(); //save state of the originator
}

void
Game::showBoard()
{
	board->showBoard();
}

void
Game::deal()
{
	board->deal();
	registry();
}

void
Game::moveBetweenPiles(int thePileOriginNumber,
	     	 	 	  int thePileDestinationNumber,
					  int theCardOriginNumber)
{
	board->moveBetweenPiles(thePileOriginNumber, thePileDestinationNumber, theCardOriginNumber);
	registry();
}

void
Game::moveBetweenWastePileAndPile(int thePileDestinationNumber)
{
	board->moveBetweenWastePileAndPile(thePileDestinationNumber);
	registry();
}

void
Game::moveBetweenWastePileAndFoundation()
{
	board->moveBetweenWastePileAndFoundation();
	registry();
}

void
Game::moveBetweenPileAndFoundation(int thePileOriginNumber)
{
	board->moveBetweenPileAndFoundation(thePileOriginNumber);
	registry();
}

bool
Game::hasWon()
{
	if (board->hasWon())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void
Game::clear()
{
	board->clear();
}

void
Game::undo()
{
    if (firstPrevious <= (mementoList.size() - 1))
    {
		firstPrevious++;
		cout << "Game::undo MEMLIST " << mementoList.size() <<endl;
		cout << "Game::undo FIRSTPREV " << firstPrevious <<endl;
		set(mementoList[(mementoList.size()-1)-firstPrevious]);
		/*if (!mementoList.empty())
		{
			cout << "Game::undo MEMLIST " << mementoList.size() <<endl;
			cout << "Game::undo FIRSTPREV " << firstPrevious <<endl;
			//serialize();
			if (firstPrevious >= mementoList.size())
			{
				cout << "Game::undo First Element no possible to do undo" <<endl;
			}
			else //From second movement we can undo()
			{
				firstPrevious++;
				cout << "Game::undo FIRSTPREV " << firstPrevious <<endl;
				set(mementoList[(mementoList.size()-1)-firstPrevious]);
			}
		}*/
    }
}

void
Game::redo()
{
	if (firstPrevious >= 1)
	{
		if (!mementoList.empty())
		{
			firstPrevious--;
			cout << "Game::redo MEMLIST " << mementoList.size() <<endl;
			cout << "Game::redo FIRSTPREV " << firstPrevious <<endl;
			set(mementoList[(mementoList.size()-1)-firstPrevious]);
		}
	}
}

void
Game::registry()
{
	cout << "Game::registry MEMLIST before" << mementoList.size() <<endl;
	cout << "Game::registry FIRSTPREV " << firstPrevious <<endl;
	for (int i = 0; i < firstPrevious; i++)
	{
		mementoList.erase(mementoList.end());
	}
	firstPrevious = 0;
	mementoList.push_back(createMemento());
	cout << "Game::registry MEMLIST after " << mementoList.size() <<endl;
}

shared_ptr<GameMemento>
Game::createMemento()
{
	cout << "createMemento"<<endl;
	return shared_ptr<GameMemento>(new GameMemento(board->getStock(),
												   board->getWastePile(),
												   board->getPiles(),
												   board->getFoundations()));
}

void
Game::set(shared_ptr<GameMemento> gameMemento)
{
	board->setStock(gameMemento->getStock());
	board->setWastePile(gameMemento->getWastePile());
	board->setPiles(gameMemento->getPiles());
	board->setFoundations(gameMemento->getFoundations());
}

void
Game::serialize()
{
    //std::vector<CardInBoard> vec;
    // add some elements into vec...

	std::cout << "Game::serialize()" << std::endl;
    // you can serialize CardInBoard directly
    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, board->getStock());

    msgpack::object_handle oh =
        msgpack::unpack(sbuf.data(), sbuf.size());

    msgpack::object obj = oh.get();
    std::cout << obj << std::endl;

    // you can convert object to CardInBoard directly
    std::vector<CardInBoard> rvec;
    obj.convert(rvec);


    /*my m1(42);
    msgpack::zone z;
    msgpack::object obj(m1, z);
    std::cout << obj << std::endl;
    assert(m1.a == obj.as<my>().a);

    assert(board->getStock() == obj.as<CardInBoard>());*/
/*}

void
Game::showElement(vector<CardInBoard> theElement)
{*/
    if (rvec.empty())
    {
    	cout << "== EMPTY ==" << endl;
    }
    else
    {
    	cout << "Cards:";
    	for(vector<CardInBoard>::iterator it = rvec.begin(); it != rvec.end(); it++)
		{
    		//Only show cards upturned, X for downturned
    		cout << " ";
    		if ((*it).getUpOrDownTurned() == CardInBoard::TurnedEnum::DOWN)
    		{
    			cout << "X";
    		}
    		else if ((*it).getUpOrDownTurned() == CardInBoard::TurnedEnum::UP)
    		{
    			cout << ((*it).getCard())->getNumber() << (*it).getCard()->getSuit()->toString((*it).getCard()->getSuit()->getSuit());
    		}
    		else
    		{
    			cout << "Impossible situation." << endl;
    		}
		}
    }
    cout << endl;
}

