#include <MementoRegistry.h>

MementoRegistry::~MementoRegistry() {

}

MementoRegistry::MementoRegistry()
{

}

MementoRegistry::MementoRegistry(shared_ptr<Game> theGame)
{
	game = theGame;

	redoUndoIndex = 0;
}


void
MementoRegistry::registry()
{
	for (int i = 0; i < redoUndoIndex; i++)
	{
		mementoList.erase(mementoList.end());
	}
	redoUndoIndex = 0;
	mementoList.push_back(game->createMemento());
}

void
MementoRegistry::undo()
{
	if (redoUndoIndex < (mementoList.size() - 1))
    {
		redoUndoIndex++;
		game->set(mementoList[(mementoList.size()-1)-redoUndoIndex]);
    }
}

void
MementoRegistry::redo()
{
	if (redoUndoIndex >= 1)
	{
		if (!mementoList.empty())
		{
			redoUndoIndex--;
			game->set(mementoList[(mementoList.size()-1)-redoUndoIndex]);
		}
	}
}
