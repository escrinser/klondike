#ifndef VIEWS_CONTINUEVIEW_H_
#define VIEWS_CONTINUEVIEW_H_

class ContinueController;

class ContinueView {
public:
	ContinueView();
	virtual ~ContinueView();
	void interact(ContinueController* continueController);
};

#endif /* VIEWS_CONTINUEVIEW_H_ */
