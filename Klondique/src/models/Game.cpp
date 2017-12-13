#include "Game.h"
#include "Board.h"

Game::Game() {
	state = State::INITIAL;

	shared_ptr<Deck> deck (new Deck());
	vector<shared_ptr<Suit>> allSuites;

	allSuites.push_back(shared_ptr<Suit>(new Suit(SuitType::HEART, SuitColor::RED, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(SuitType::SPADE, SuitColor::BLACK, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(SuitType::CLUB, SuitColor::BLACK, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(SuitType::DIAMOND, SuitColor::RED, NUMBER_OF_CARDS)));

	deck->loadDeck(allSuites);
	board = shared_ptr<Board>(new Board(deck));
}

Game::~Game() {
}

void
Game::startPlayingBoard()
{
	board->startPlayingBoard();
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
	mementoList.push_back(createMemento());
}

void
Game::moveBetweenPiles(int thePileOriginNumber,
	     	 	 	  int thePileDestinationNumber,
					  int theCardOriginNumber)
{
	board->moveBetweenPiles(thePileOriginNumber, thePileDestinationNumber, theCardOriginNumber);
	mementoList.push_back(createMemento());
}

void
Game::moveBetweenWastePileAndPile(int thePileDestinationNumber)
{
	board->moveBetweenWastePileAndPile(thePileDestinationNumber);
	mementoList.push_back(createMemento());
}

void
Game::moveBetweenWastePileAndFoundation()
{
	board->moveBetweenWastePileAndFoundation();
	mementoList.push_back(createMemento());
}

void
Game::moveBetweenPileAndFoundation(int thePileOriginNumber)
{
	board->moveBetweenPileAndFoundation(thePileOriginNumber);
	mementoList.push_back(createMemento());
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
	cout << "Game::undo"<<endl;
	set(mementoList.back());
}


shared_ptr<GameMemento>
Game::createMemento()
{
	cout << "createMemento"<<endl;
	return shared_ptr<GameMemento>(new GameMemento(board));
}

void
Game::set(shared_ptr<GameMemento> gameMemento)
{
	cout << "Game::set"<<endl;
	board = gameMemento->board;

	cout << "Game::set"<<endl;
	showBoard();
}

