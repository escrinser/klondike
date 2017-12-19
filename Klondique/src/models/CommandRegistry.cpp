#include <CommandRegistry.h>

CommandRegistry::~CommandRegistry() {

}

CommandRegistry::CommandRegistry()
{

}

CommandRegistry::CommandRegistry(shared_ptr<Game> theGame)
{
	game = theGame;

	redoUndoIndex = 0;
}


void
CommandRegistry::registry()
{
	for (int i = 0; i < redoUndoIndex; i++)
	{
		commandList.erase(commandList.end());
	}
	redoUndoIndex = 0;
	commandList.push_back(game->createMemento());
}

void
CommandRegistry::undo()
{
	if (redoUndoIndex < (commandList.size() - 1))
    {
		redoUndoIndex++;
		cout << "CommandRegistry::undo MEMLIST " << commandList.size() <<endl;
		cout << "CommandRegistry::undo FIRSTPREV " << redoUndoIndex <<endl;
		game->set(commandList[(commandList.size()-1)-redoUndoIndex]);
    }
}

void
CommandRegistry::redo()
{
	if (redoUndoIndex >= 1)
	{
		if (!commandList.empty())
		{
			redoUndoIndex--;
			cout << "CommandRegistry::redo MEMLIST " << commandList.size() <<endl;
			cout << "CommandRegistry::redo FIRSTPREV " << redoUndoIndex <<endl;
			game->set(commandList[(commandList.size()-1)-redoUndoIndex]);
		}
	}
}
