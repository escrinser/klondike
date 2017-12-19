#ifndef GAME_H_
#define GAME_H_

#include "State.h"
#include "Board.h"
#include "Deck.h"
#include "CardInBoard.h"
#include "Card.h"

#include "GameMemento.h"
//#include "MementoRegistry.h"

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

	void startPlayingBoard();

	void showBoard();

	void deal();

	void moveBetweenPiles(int thePileOriginNumber,
		     	 	 	  int thePileDestinationNumber,
						  int theCardOriginNumber);

	void moveBetweenWastePileAndPile(int thePileDestinationNumber);

	void moveBetweenWastePileAndFoundation();
	void moveBetweenPileAndFoundation(int thePileOriginNumber);

	bool hasWon();

	void clear();

	void undo();
	void redo();
	void registry();

	shared_ptr<GameMemento> createMemento();
	void set(shared_ptr<GameMemento> gameMemento);

	void saveGame();
	void recoverGame();

private:
	State state;
	shared_ptr<Deck> deck;
	shared_ptr<Board> board;

	//TODO: Here or in MementoRegistry?
	vector<shared_ptr<GameMemento>> mementoList;
	int firstPrevious = 0;

	//MementoRegistry* mementoRegistry;
};

#endif /* GAME_H_ */
