#ifndef MODELS_UNDOABLECOMMAND_H_
#define MODELS_UNDOABLECOMMAND_H_

#define MENU_OPTION_1 1
#define MENU_OPTION_2 2
#define MENU_OPTION_3 3
#define MENU_OPTION_4 4
#define MENU_OPTION_6 6
#define MENU_OPTION_7 7
#define MENU_OPTION_8 8

#define MIN_NUMBER_OF_CARDS 1
#define MAX_NUMBER_OF_CARDS 13

#define MIN_NUMBER_OF_PILES 1
#define MAX_NUMBER_OF_PILES 7

#include "Command.h"

class UndoableCommand : public Command{
public:
	UndoableCommand(std::string title, shared_ptr<Game> game);

	virtual ~UndoableCommand();

	virtual void undo() = 0;

	virtual void redo() = 0;

	//virtual UndoableCommand clone() = 0;

	//void execute();

	//bool isActive();

};

#endif /* MODELS_UNDOABLECOMMAND_H_ */
