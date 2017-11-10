/*
 * Game.h
 *
 *  Created on: 8 nov. 2017
 *      Author: eseogaz
 */

#ifndef GAME_H_
#define GAME_H_

#include "State.h"
#include "Board.h"
#include "Deck.h"
#include "CardInBoard.h"
#include "Card.h"

class Game {
public:
	Game();
	virtual ~Game();

	const shared_ptr<Board>& getBoard() const {
		return board;
	}

	void setBoard(const shared_ptr<Board>& board) {
		this->board = board;
	}

	const shared_ptr<Deck>& getDeck() const {
		return deck;
	}

	void setDeck(const shared_ptr<Deck>& deck) {
		this->deck = deck;
	}

	State getState() const {
		return state;
	}

	void setState(State state) {
		this->state = state;
	}

	bool hasWon();

	void clear();

	//Other methods with Board like move....

private:
	State state;
	shared_ptr<Deck> deck;
	shared_ptr<Board> board;
};

#endif /* GAME_H_ */
