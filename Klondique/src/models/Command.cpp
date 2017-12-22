#include <Command.h>

Command::~Command() {

}

Command::Command(std::string theTitle, shared_ptr<Game> theGame)
{
	title = theTitle;
	game = theGame;
}

std::string
Command::getTitle()
{
	return title;
}
