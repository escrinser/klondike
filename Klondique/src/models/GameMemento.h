#ifndef MODELS_GAMEMEMENTO_H_
#define MODELS_GAMEMEMENTO_H_

#include "Board.h"

class GameMemento {
public:
	GameMemento(vector<shared_ptr<CardInBoard>> theStock,
		     vector<shared_ptr<CardInBoard>> theWastePile,
			 vector<vector<shared_ptr<CardInBoard>>> thePiles,
			 vector<vector<shared_ptr<CardInBoard>>> theFoundations);
	virtual ~GameMemento();

	vector<shared_ptr<CardInBoard>> getStock();
	vector<shared_ptr<CardInBoard>> getWastePile();
	vector<vector<shared_ptr<CardInBoard>>> getPiles();
	vector<vector<shared_ptr<CardInBoard>>> getFoundations();

	void setStock(vector<shared_ptr<CardInBoard>> theStock);
	void setWastePile(vector<shared_ptr<CardInBoard>> theWastePile);
	void setPiles(vector<vector<shared_ptr<CardInBoard>>> thePiles);
	void setFoundations(vector<vector<shared_ptr<CardInBoard>>> theFoundations);

private:
	vector<shared_ptr<CardInBoard>> stock;
	vector<shared_ptr<CardInBoard>> wastePile;
	vector<vector<shared_ptr<CardInBoard>>> piles;
	vector<vector<shared_ptr<CardInBoard>>> foundations;
};

#endif /* MODELS_GAMEMEMENTO_H_ */
