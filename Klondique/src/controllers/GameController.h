#ifndef CONTROLLERS_GAMECONTROLLER_H_
#define CONTROLLERS_GAMECONTROLLER_H_

#include "OperationController.h"

class GameController : public OperationController{
public:
	GameController() {};
	virtual ~GameController() {};
	virtual void deal() = 0;

	virtual void moveBetweenPiles(int thePileOriginNumber,
		     	 	 	  int thePileDestinationNumber,
						  int theCardOriginNumber) = 0;

	virtual void moveBetweenWastePileAndPile(int thePileDestinationNumber) = 0;

	virtual void moveBetweenWastePileAndFoundation() = 0;
	virtual void moveBetweenPileAndFoundation(int thePileOriginNumber) = 0;
	virtual bool hasWon() = 0;

	virtual void undo()=0;
};

#endif /* CONTROLLERS_GAMECONTROLLER_H_ */
