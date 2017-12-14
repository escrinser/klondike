#include <GameMemento.h>

GameMemento::GameMemento(vector<shared_ptr<CardInBoard>> theStock,
					     vector<shared_ptr<CardInBoard>> theWastePile,
						 vector<vector<shared_ptr<CardInBoard>>> thePiles,
						 vector<vector<shared_ptr<CardInBoard>>> theFoundations)
{
	stock = theStock;
	wastePile = theWastePile;
	piles = thePiles;
	foundations = theFoundations;
}

GameMemento::~GameMemento() {
	// TODO Auto-generated destructor stub
}

vector<shared_ptr<CardInBoard>>
GameMemento::getStock()
{
	return stock;
}

vector<shared_ptr<CardInBoard>>
GameMemento::getWastePile()
{
	return wastePile;
}

vector<vector<shared_ptr<CardInBoard>>>
GameMemento::getPiles()
{
	return piles;
}

vector<vector<shared_ptr<CardInBoard>>>
GameMemento::getFoundations()
{
	return foundations;
}

void
GameMemento::setStock(vector<shared_ptr<CardInBoard>> theStock)
{
	stock = theStock;
}

void
GameMemento::setWastePile(vector<shared_ptr<CardInBoard>> theWastePile)
{
	wastePile = theWastePile;
}

void
GameMemento::setPiles(vector<vector<shared_ptr<CardInBoard>>> thePiles)
{
	piles = thePiles;
}

void
GameMemento::setFoundations(vector<vector<shared_ptr<CardInBoard>>> theFoundations)
{
	foundations = theFoundations;
}


