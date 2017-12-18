#include <MementoRegistry.h>

MementoRegistry::~MementoRegistry() {
	// TODO Auto-generated destructor stub
}

MementoRegistry::MementoRegistry(Game* theGame)
{
	this->game = theGame;

	mementoList.push_back(theGame->createMemento());

	firstPrevious = 0;
}

void
MementoRegistry::registry()
{
	for (int i = 0; i < firstPrevious; i++)
	{
		mementoList.erase(mementoList.begin()+i);
	}
	firstPrevious = 0;
	mementoList.push_back(game->createMemento());
}

void
MementoRegistry::undo(Game game)
{
	firstPrevious++;
	if (!mementoList.empty())
	{
		cout << "MementoRegistry::undo " << mementoList.size() <<endl;

		game.set(mementoList[mementoList.size()-2]); //TODO: Only undo last movement
		//set(mementoList.back());
	}
}

void
MementoRegistry::redo(Game game)
{
	firstPrevious--;
	//game->set(mementoList[0]);
	if (!mementoList.empty())
	{
		cout << "MementoRegistry::redo " << mementoList.size() <<endl;
		game.set(mementoList[mementoList.size()-1]); //TODO: Only redo last movement
		//set(mementoList.back());
	}
}

//save state of the originator
//void
//MementoRegistry::SaveState(shared_ptr<Game> game
void
MementoRegistry::SaveState()
{
	mementoList.push_back(game->createMemento());
}

//restore state of the originator
void
MementoRegistry::RestoreState(int stateNumber)
{
	game->set(mementoList[stateNumber]);
}



