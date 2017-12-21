#include "Game.h"
#include "Board.h"
#include <msgpack/fbuffer.hpp>

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>

Game::Game()
{
	state = State::INITIAL;

	shared_ptr<Deck> deck (new Deck());
	vector<shared_ptr<Suit>> allSuites;

	allSuites.push_back(shared_ptr<Suit>(new Suit(Suit::SuitType::HEART, Suit::SuitColor::RED, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(Suit::SuitType::SPADE, Suit::SuitColor::BLACK, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(Suit::SuitType::CLUB, Suit::SuitColor::BLACK, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(Suit::SuitType::DIAMOND, Suit::SuitColor::RED, NUMBER_OF_CARDS)));

	deck->loadDeck(allSuites);
	board = shared_ptr<Board>(new Board(deck));

    std::shared_ptr<Game> sharedGame;
    sharedGame.reset(this);
	mementoRegistry = std::make_shared<MementoRegistry>(sharedGame);
}

Game::~Game() {
}

void
Game::startPlayingBoard()
{
	board->startPlayingBoard();
	registry();
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
	mementoRegistry->undo();
}

void
Game::redo()
{
	mementoRegistry->redo();
}

void
Game::registry()
{
	mementoRegistry->registry();
}

shared_ptr<GameMemento>
Game::createMemento()
{
	return shared_ptr<GameMemento>(new GameMemento(board->getStock(),
												   board->getWastePile(),
												   board->getPiles(),
												   board->getFoundations()));
}

void
Game::set(shared_ptr<GameMemento> gameMemento)
{
	board->setStock(gameMemento->stock);
	board->setWastePile(gameMemento->wastePile);
	board->setPiles(gameMemento->piles);
	board->setFoundations(gameMemento->foundations);
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
