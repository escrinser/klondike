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
	// TODO Auto-generated destructor stub
}

vector<CardInBoard>
GameMemento::getStock()
{
	return stock;
}

vector<CardInBoard>
GameMemento::getWastePile()
{
	return wastePile;
}

vector<vector<CardInBoard>>
GameMemento::getPiles()
{
	return piles;
}

vector<vector<CardInBoard>>
GameMemento::getFoundations()
{
	return foundations;
}

void
GameMemento::setStock(vector<CardInBoard> theStock)
{
	stock = theStock;
}

void
GameMemento::setWastePile(vector<CardInBoard> theWastePile)
{
	wastePile = theWastePile;
}

void
GameMemento::setPiles(vector<vector<CardInBoard>> thePiles)
{
	piles = thePiles;
}

void
GameMemento::setFoundations(vector<vector<CardInBoard>> theFoundations)
{
	foundations = theFoundations;
}


