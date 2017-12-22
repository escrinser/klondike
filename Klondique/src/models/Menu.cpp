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
//#include "StartMenuCommand.h"
#include "ContinueMenuCommand.h"

#include "LimitedInDialog.h"
#include "IO.h"

Menu::~Menu() {
}

Menu::Menu(shared_ptr<Game> theGame)
{
	game = theGame;

	allCommandList.push_back(shared_ptr<PlayCommand>(new PlayCommand(game)));
	allCommandList.push_back(shared_ptr<RecoverGameCommand>(new RecoverGameCommand(game)));

	allCommandList.push_back(shared_ptr<DealCommand>(new DealCommand(game)));
	allCommandList.push_back(shared_ptr<MoveBetweenPileAndFoundation>(new MoveBetweenPileAndFoundation(game)));
	allCommandList.push_back(shared_ptr<MoveBetweenWastePileAndPile>(new MoveBetweenWastePileAndPile(game)));
	allCommandList.push_back(shared_ptr<MoveBetweenWastePileAndFoundation>(new MoveBetweenWastePileAndFoundation(game)));
	allCommandList.push_back(shared_ptr<MoveBetweenPiles>(new MoveBetweenPiles(game)));

	allCommandList.push_back(shared_ptr<UndoCommand>(new UndoCommand(game)));
	allCommandList.push_back(shared_ptr<RedoCommand>(new RedoCommand(game)));
	//allCommandList.push_back(shared_ptr<StartMenuCommand>(new StartMenuCommand(game)));
	allCommandList.push_back(shared_ptr<ContinueMenuCommand>(new ContinueMenuCommand(game)));

	allCommandList.push_back(shared_ptr<ContinueCommand>(new ContinueCommand(game)));
    allCommandList.push_back(shared_ptr<SaveGameCommand>(new SaveGameCommand(game)));

    exitCommand = shared_ptr<ExitCommand>(new ExitCommand(game));
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
		IO::getInstance()->writeln(std::to_string(i + 1) + ". " + actualCommandList[i]->getTitle());
	}
}

int
Menu::getOption()
{
	string title = "Option ";
	return LimitedInDialog::getInstance()->read(title, MENU_OPTION_1, actualCommandList.size()) - 1;
}

bool
Menu::isClosed()
{
	return exitCommand->closed();
}

