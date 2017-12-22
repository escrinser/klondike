#include <UndoableCommand.h>

UndoableCommand::UndoableCommand(std::string title, shared_ptr<Game> game):
	Command(title, game)
{

}

UndoableCommand::~UndoableCommand() {
}

