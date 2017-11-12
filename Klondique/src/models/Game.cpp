/*
 * Game.cpp
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#include "Game.h"
#include "Board.h"

#define NUMBER_OF_PILES 7
#define NUMBER_OF_FOUNDATIONS 4
#define NUMBER_OF_CARDS 13

Game::Game() {
	state = State::INITIAL;

	shared_ptr<Deck> deck (new Deck()); //TODO: Load Deck inside Deck constructor
	vector<shared_ptr<Suit>> allSuites;

	allSuites.push_back(shared_ptr<Suit>(new Suit(SuitType::HEART, SuitColor::RED, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(SuitType::SPADE, SuitColor::BLACK, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(SuitType::CLUB, SuitColor::BLACK, NUMBER_OF_CARDS)));
	allSuites.push_back(shared_ptr<Suit>(new Suit(SuitType::DIAMOND, SuitColor::RED, NUMBER_OF_CARDS)));

	deck->loadDeck(allSuites);
	board = shared_ptr<Board>(new Board(deck));
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void
Game::initBoard()
{
	board->initBoard();
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
}

void
Game::moveBetweenPiles(int thePileOriginNumber,
	     	 	 	  int thePileDestinationNumber,
					  int theCardOriginNumber)
{
	board->moveBetweenPiles(thePileOriginNumber, thePileDestinationNumber, theCardOriginNumber);
}

void
Game::moveBetweenWastePileAndPile(int thePileDestinationNumber)
{
	board->moveBetweenWastePileAndPile(thePileDestinationNumber);
}

void
Game::moveBetweenWastePileAndFoundation()
{
	board->moveBetweenWastePileAndFoundation();
}

void
Game::moveBetweenPileAndFoundation(int thePileOriginNumber)
{
	board->moveBetweenPileAndFoundation(thePileOriginNumber);
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

