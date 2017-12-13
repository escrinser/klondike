#ifndef LOCALGAMECONTROLLER_H_
#define LOCALGAMECONTROLLER_H_

#include <memory>

#include "../GameController.h"

class Game;

using namespace std;

class LocalGameController : public GameController{
public:
	LocalGameController(shared_ptr<Game> theGame): GameController(), game(theGame){};
	virtual ~LocalGameController();

	void deal();

	void moveBetweenPiles(int thePileOriginNumber,
		     	 	 	  int thePileDestinationNumber,
						  int theCardOriginNumber);

	void moveBetweenWastePileAndPile(int thePileDestinationNumber);

	void moveBetweenWastePileAndFoundation();
	void moveBetweenPileAndFoundation(int thePileOriginNumber);

	void accept(OperationControllerVisitor* operationControllerVisitor);

	bool hasWon();

	void setState(State state);
	void printBoard();
	void undo();
private:
	shared_ptr<Game> game;
};

#endif /* LOCALGAMECONTROLLER_H_ */
