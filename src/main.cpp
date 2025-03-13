#include <iostream>

#include "Shell.hpp"
#include "Command.hpp"

using namespace shell;
using namespace command;

void registerCommands() {
    Command::registerCommand<HelpCommand>("help");
    Command::registerCommand<ExitCommand>("exit");
}

int main() {
    registerCommands();

    Shell::getInstance().run();

    return 0;
}