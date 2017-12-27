#ifndef CONTROLLERS_MENUVISITOR_H_
#define CONTROLLERS_MENUVISITOR_H_

class Menu;

class MenuVisitor {
public:
	MenuVisitor();
	virtual ~MenuVisitor();

	void virtual visit(Menu* menu) = 0;
};

#endif /* CONTROLLERS_MENUVISITOR_H_ */
