#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include <memory>
#include "OperationController.h"

class Game;

using namespace std;

class GameController : public OperationController{
public:
	GameController(shared_ptr<Game> theGame): OperationController(theGame), game(theGame){};
	virtual ~GameController();
	void showBoard(); //TODO: Colaborate with BoardView
	void deal();

	void moveBetweenPiles(int thePileOriginNumber,
		     	 	 	  int thePileDestinationNumber,
						  int theCardOriginNumber);

	void moveBetweenWastePileAndPile(int thePileDestinationNumber);

	void moveBetweenWastePileAndFoundation();
	void moveBetweenPileAndFoundation(int thePileOriginNumber);

	void accept(OperationControllerVisitor* operationControllerVisitor);
private:
	shared_ptr<Game> game;
};

#endif /* GAMECONTROLLER_H_ */
