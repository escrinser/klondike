#include <GameMemento.h>

GameMemento::GameMemento(shared_ptr<Board> theBoard)
{
board = theBoard;
}

GameMemento::~GameMemento() {
	// TODO Auto-generated destructor stub
}

