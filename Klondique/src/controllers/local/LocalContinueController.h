#ifndef LOCALCONTINUECONTROLLER_H_
#define LOCALCONTINUECONTROLLER_H_

#include <LocalOperationControllerVisitor.h>
#include <LocalOperationController.h>
#include <memory>


class Game;

using namespace std;

class LocalContinueController : public LocalOperationController{
public:
	LocalContinueController(shared_ptr<Game> theGame): LocalOperationController(theGame), game(theGame){};
	virtual ~LocalContinueController();
	void setContinue(int theOption);
	void accept(LocalOperationControllerVisitor* operationControllerVisitor);
private:
	shared_ptr<Game> game;
};

#endif /* LOCALCONTINUECONTROLLER_H_ */
