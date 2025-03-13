#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <sstream>
#include <iostream>

#include "Shell.hpp"

namespace command {

class HelpCommand : public shell::Command {
public:
    bool execute(const std::istringstream& args) override {
        std::cout << "Help command executed" << std::endl;
        std::cout << "Arguments: " << args.str() << std::endl;

        return true;
    }
};

class ExitCommand : public shell::Command {
public:
    bool execute(const std::istringstream& args) override {
        std::cout << "Exit command executed" << std::endl;
        std::cout << "Arguments: " << args.str() << std::endl;

        return false;
    }
};
    
}; // namespace command

#endif // COMMAND_HPP