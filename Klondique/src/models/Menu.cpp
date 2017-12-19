#include <Menu.h>
#include "LimitedInDialog.h"

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

Menu::Menu(shared_ptr<Game> theGame)
{
	game = theGame;
	//actualCommandList = new ArrayList<Command>();
	commandRegistry = shared_ptr<CommandRegistry>(new CommandRegistry());
	//allCommandList = new ArrayList<Command>();
	//allCommandList.add(new PutCommand(game, commandRegistry));
	//allCommandList.add(new MoveCommand(game, commandRegistry));
	//allCommandList.add(new UndoCommand(game, commandRegistry));
	//allCommandList.add(new RedoCommand(game, commandRegistry));
	exitCommand = shared_ptr<ExitCommand>(new ExitCommand());
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
		//game.write();
		this->write();
		int option = this->getOption();
		actualCommandList[option]->execute();
	} while (!this->isClosed());
}

void
Menu::write()
{
	cout << "---------------------" << endl;
	for (int i = 0; i < actualCommandList.size(); i++)
	{
		cout << (i + 1) << ". " << actualCommandList[i]->getTitle() << endl;
	}
}

int
Menu::getOption()
{
	/*return LimitedIntDialog.instance()
			.read("Opción", 1, actualCommandList.size()) - 1;*/
	/*return LimitedInDialog startDialog ("Chose one option:\n\n"
				"1  Play\n"
			    "2  Recover game from file\n"
			    "3  Exit\n"
				"Enter your choice and press return:", MENU_OPTION_1, MENU_OPTION_3);*/
	return 3;
}

bool
Menu::isClosed()
{
	return exitCommand->closed();
}

