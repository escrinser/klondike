#ifndef VIEWS_STARTVIEW_H_
#define VIEWS_STARTVIEW_H_

class StartController;

class StartView {
public:
	StartView();
	virtual ~StartView();
	void interact(StartController* startController);
};

#endif /* VIEWS_STARTVIEW_H_ */
