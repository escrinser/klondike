#include <UndoableCommand.h>

UndoableCommand::UndoableCommand(std::string title, shared_ptr<Game> game, shared_ptr<CommandRegistry> commandRegistry):
	Command(title, game, commandRegistry)
{

}

UndoableCommand::~UndoableCommand() {
}

