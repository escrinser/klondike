#ifndef LOCALOPERATIONCONTROLLER_H_
#define LOCALOPERATIONCONTROLLER_H_

#include <LocalOperationControllerVisitor.h>
#include <LocalController.h>
#include <memory>


class Game;
class KlondiqueView;

using namespace std;

class LocalOperationController : public LocalController {
public:
	LocalOperationController(shared_ptr<Game> theGame): LocalController(theGame), game(theGame){};
	virtual ~LocalOperationController();
	virtual void accept(LocalOperationControllerVisitor* operationControllerVisitor) = 0;
private:
	shared_ptr<Game> game;
};

#endif /* LOCALOPERATIONCONTROLLER_H_ */
