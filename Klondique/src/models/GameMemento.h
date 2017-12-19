#ifndef MODELS_GAMEMEMENTO_H_
#define MODELS_GAMEMEMENTO_H_

#include "Board.h"
#include "CardInBoard.h"

class Game;

class GameMemento {
public:
	GameMemento(vector<CardInBoard> theStock,
		     vector<CardInBoard> theWastePile,
			 vector<vector<CardInBoard>> thePiles,
			 vector<vector<CardInBoard>> theFoundations);
	virtual ~GameMemento();

private:

	friend class Game;

	vector<CardInBoard> stock;
	vector<CardInBoard> wastePile;
	vector<vector<CardInBoard>> piles;
	vector<vector<CardInBoard>> foundations;
};

#endif /* MODELS_GAMEMEMENTO_H_ */
