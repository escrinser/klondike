#ifndef LOCALGAMECONTROLLER_H_
#define LOCALGAMECONTROLLER_H_

#include <memory>

#include "GameController.h"
#include "LocalOperationController.h"

class Game;

using namespace std;

class LocalGameController : public GameController, LocalOperationController{
public:
	LocalGameController(shared_ptr<Game> theGame): LocalOperationController(theGame), game(theGame){};
	virtual ~LocalGameController();
	void showBoard(); //TODO: Colaborate with BoardView
	void deal();

	void moveBetweenPiles(int thePileOriginNumber,
		     	 	 	  int thePileDestinationNumber,
						  int theCardOriginNumber);

	void moveBetweenWastePileAndPile(int thePileDestinationNumber);

	void moveBetweenWastePileAndFoundation();
	void moveBetweenPileAndFoundation(int thePileOriginNumber);

	void accept(OperationControllerVisitor* operationControllerVisitor);

	bool hasWon();
private:
	shared_ptr<Game> game;
};

#endif /* LOCALGAMECONTROLLER_H_ */
