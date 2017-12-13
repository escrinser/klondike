#ifndef MODELS_GAMEMEMENTO_H_
#define MODELS_GAMEMEMENTO_H_

#include "Board.h"

class GameMemento {
public:
	GameMemento(shared_ptr<Board> board);
	virtual ~GameMemento();

//private:
	shared_ptr<Board> board;
};

#endif /* MODELS_GAMEMEMENTO_H_ */
