#include <GameMemento.h>

GameMemento::GameMemento(vector<CardInBoard> theStock,
					     vector<CardInBoard> theWastePile,
						 vector<vector<CardInBoard>> thePiles,
						 vector<vector<CardInBoard>> theFoundations)
{
	stock = theStock;
	wastePile = theWastePile;
	piles = thePiles;
	foundations = theFoundations;
}

GameMemento::~GameMemento() {

}


