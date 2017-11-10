/*
 * Game.cpp
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#include "Game.h"


Game::Game() {
	state = State::INITIAL;

	board = shared_ptr<Board>(new Board(deck));
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

bool
Game::hasWon()
{
	if (board->hasWon())
	{
		cout << "You win!!!" << endl;
		return true;
	}
	else
	{
		cout << "You are on the way to win, keep trying..." << endl;
		return false;
	}
}

void
Game::clear()
{
	board->clear();
}

