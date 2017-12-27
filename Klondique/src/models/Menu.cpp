#include <Menu.h>
#include <MoveBetweenPileAndFoundationCommand.h>
#include <MoveBetweenPilesCommand.h>
#include <MoveBetweenWastePileAndFoundationCommand.h>
#include <MoveBetweenWastePileAndPileCommand.h>

#include "PlayCommand.h"
#include "ContinueCommand.h"
#include "SaveGameCommand.h"
#include "RecoverGameCommand.h"
#include "DealCommand.h"
#include "RedoCommand.h"
#include "UndoCommand.h"
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
	allCommandList.push_back(shared_ptr<MoveBetweenPileAndFoundationCommand>(new MoveBetweenPileAndFoundationCommand(game)));
	allCommandList.push_back(shared_ptr<MoveBetweenWastePileAndPileCommand>(new MoveBetweenWastePileAndPileCommand(game)));
	allCommandList.push_back(shared_ptr<MoveBetweenWastePileAndFoundationCommand>(new MoveBetweenWastePileAndFoundationCommand(game)));
	allCommandList.push_back(shared_ptr<MoveBetweenPilesCommand>(new MoveBetweenPilesCommand(game)));

	allCommandList.push_back(shared_ptr<UndoCommand>(new UndoCommand(game)));
	allCommandList.push_back(shared_ptr<RedoCommand>(new RedoCommand(game)));
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
		if (command->isActive())
		{
			actualCommandList.push_back(command);
		}
	}
}

void
Menu::execute()
{
	do {
		this->setActualCommands();
		game->showBoard();
		this->write();
		int option = this->getOption();
		actualCommandList[option]->execute();
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


void
Menu::accept(MenuVisitor* menuVisitor)
{
	menuVisitor->visit(this);
}
