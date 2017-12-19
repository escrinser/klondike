#include "Game.h"
#include "Board.h"
#include <msgpack/fbuffer.hpp>

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>

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
Game::saveGame()
{
	// Serialize it. (THIS WORKS!)
	{
		std::ofstream ofs("klondike.bin");
		msgpack::pack(ofs, board);
	} // automatically close here.

	std::cout << "Board save in file klondike.bin" << std::endl;
}

void
Game::recoverGame()
{
	// Deserialize the serialized data
	std::ifstream ifs("klondike.bin", std::ifstream::in);
	std::stringstream buffer;
	buffer << ifs.rdbuf();
	msgpack::unpacked upd;
	msgpack::unpack(upd, buffer.str().data(), buffer.str().size());
	//std::cout << upd.get() << std::endl;
	msgpack::object obj2 = upd.get();

	shared_ptr<Board> recoveredBoard;
	obj2.convert(recoveredBoard);

	board = recoveredBoard;
	std::cout << "Board recovered from file klondike.bin" << std::endl;
}
