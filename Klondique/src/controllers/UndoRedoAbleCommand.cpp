#include <UndoRedoAbleCommand.h>

UndoRedoAbleCommand::UndoRedoAbleCommand(std::string title, shared_ptr<Game> game):
	Command(title, game)
{

}

UndoRedoAbleCommand::~UndoRedoAbleCommand() {
}

