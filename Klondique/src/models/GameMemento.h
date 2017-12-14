#ifndef MODELS_GAMEMEMENTO_H_
#define MODELS_GAMEMEMENTO_H_

#include "Board.h"
#include "CardInBoard.h"

class GameMemento {
public:
	GameMemento(vector<CardInBoard> theStock,
		     vector<CardInBoard> theWastePile,
			 vector<vector<CardInBoard>> thePiles,
			 vector<vector<CardInBoard>> theFoundations);
	virtual ~GameMemento();

	vector<CardInBoard> getStock();
	vector<CardInBoard> getWastePile();
	vector<vector<CardInBoard>> getPiles();
	vector<vector<CardInBoard>> getFoundations();

	void setStock(vector<CardInBoard> theStock);
	void setWastePile(vector<CardInBoard> theWastePile);
	void setPiles(vector<vector<CardInBoard>> thePiles);
	void setFoundations(vector<vector<CardInBoard>> theFoundations);

private:
	vector<CardInBoard> stock;
	vector<CardInBoard> wastePile;
	vector<vector<CardInBoard>> piles;
	vector<vector<CardInBoard>> foundations;
};

#endif /* MODELS_GAMEMEMENTO_H_ */
