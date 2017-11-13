#ifndef LOCALSTARTCONTROLLER_H_
#define LOCALSTARTCONTROLLER_H_

#include <LocalOperationController.h>
#include <memory>

class Game;

using namespace std;

class LocalStartController : public LocalOperationController {
public:
	LocalStartController(shared_ptr<Game> theGame): LocalOperationController(theGame), game(theGame){};
	virtual ~LocalStartController();
	void setStart(State theState);
	void accept(LocalOperationControllerVisitor* operationControllerVisitor);
private:
	shared_ptr<Game> game;
};

#endif /* LOCALSTARTCONTROLLER_H_ */
