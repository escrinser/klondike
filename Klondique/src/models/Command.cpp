#include <Command.h>

/*Command::Command() {
	// TODO Auto-generated constructor stub

}*/

Command::~Command() {
	// TODO Auto-generated destructor stub
}

Command::Command(std::string theTitle, shared_ptr<Game> theGame, shared_ptr<CommandRegistry> theCommandRegistry)
{
	title = theTitle;
	game = theGame;
	commandRegistry = theCommandRegistry;
}

std::string
Command::getTitle()
{
	return title;
}
