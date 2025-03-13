#include <iostream>

#include "Shell.hpp"

using namespace shell;

void Shell::registerCommand(const std::string& name, std::unique_ptr<ICommand> command) {
    commandMap[name] = std::move(command);
}

void Shell::run() {
    bool running = true;
    while (running) {
        std::cout << "> ";

        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) continue;

        std::istringstream iss(input);
        std::string commandName;
        iss >> commandName;

        auto it = commandMap.find(commandName);
        if (it != commandMap.end()) {
            running = it->second->execute(iss);
        }
        else {
            std::cout << "Unknown command: " << commandName << std::endl;
        }
    }
}