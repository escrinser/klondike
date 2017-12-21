#include <Menu.h>

#include "PlayCommand.h"
#include "ContinueCommand.h"
#include "SaveGameCommand.h"
#include "RecoverGameCommand.h"
#include "DealCommand.h"
#include "MoveBetweenPileAndFoundation.h"
#include "MoveBetweenWastePileAndPile.h"
#include "MoveBetweenWastePileAndFoundation.h"
#include "MoveBetweenPiles.h"
#include "RedoCommand.h"
#include "UndoCommand.h"
#include "StartMenuCommand.h"

#include "LimitedInDialog.h"
#include "IO.h"

Menu::~Menu() {
}

Menu::Menu(shared_ptr<Game> theGame)
{
	game = theGame;

	commandRegistry = shared_ptr<CommandRegistry>(new CommandRegistry());

	allCommandList.push_back(shared_ptr<PlayCommand>(new PlayCommand(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<RecoverGameCommand>(new RecoverGameCommand(game, commandRegistry)));

	allCommandList.push_back(shared_ptr<DealCommand>(new DealCommand(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<MoveBetweenPileAndFoundation>(new MoveBetweenPileAndFoundation(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<MoveBetweenWastePileAndPile>(new MoveBetweenWastePileAndPile(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<MoveBetweenWastePileAndFoundation>(new MoveBetweenWastePileAndFoundation(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<MoveBetweenPiles>(new MoveBetweenPiles(game, commandRegistry)));

	allCommandList.push_back(shared_ptr<UndoCommand>(new UndoCommand(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<RedoCommand>(new RedoCommand(game, commandRegistry)));
	allCommandList.push_back(shared_ptr<StartMenuCommand>(new StartMenuCommand(game, commandRegistry)));

	allCommandList.push_back(shared_ptr<ContinueCommand>(new ContinueCommand(game, commandRegistry)));
    allCommandList.push_back(shared_ptr<SaveGameCommand>(new SaveGameCommand(game, commandRegistry)));

    exitCommand = shared_ptr<ExitCommand>(new ExitCommand(game, commandRegistry));
	allCommandList.push_back(exitCommand);
}

void
Menu::setActualCommands()
{
	actualCommandList.clear();
	for(shared_ptr<Command> command: allCommandList)
	{
		cout << "Try with Command: " << command->getTitle() << endl;
		if (command->isActive())
		{
			cout << "Actual Command: " << command->getTitle() << endl;
			actualCommandList.push_back(command);
		}
	}
}

void
Menu::execute()
{
	do {
		cout << "execute" << endl;
		this->setActualCommands();
		game->showBoard();
		this->write();
		int option = this->getOption();
		actualCommandList[option]->execute();
		cout << "execute end" << endl;
	} while (!this->isClosed());
}

void
Menu::write()
{
	IO::getInstance()->writeln();
	IO::getInstance()->writeln();
	IO::getInstance()->writeln("---------------------");
	for (int i = 0; i < actualCommandList.size(); i++)
	{
		IO::getInstance()->writeln((i + 1) + ". " + actualCommandList[i]->getTitle());
	}
}

int
Menu::getOption()
{
	string title = "Option ";
	return LimitedInDialog::getInstance()->read(title, MENU_OPTION_1, actualCommandList.size()) - 1;

	/*string titleStartDialog = "Chose one option:\n\n"
			"1  Play\n"
		    "2  Recover game from file\n"
		    "3  Exit\n"
			"Enter your choice and press return";
	return LimitedInDialog::getInstance()->read(titleStartDialog, MENU_OPTION_1, MENU_OPTION_3);*/
}

bool
Menu::isClosed()
{
	return exitCommand->closed();
}

