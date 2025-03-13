#pragma once

#include <memory>
#include <string>
#include <sstream>
#include <unordered_map>

namespace shell {

class ICommand {
public:
    virtual bool execute(const std::istringstream& args) = 0; // Pure virtual method for executing the command
};

class Command : public ICommand {
public:
    template <typename T>
    static void registerCommand(const std::string& name) {
        Shell::getInstance().registerCommand(name, std::make_unique<T>());
    }
};

class Shell {
public:
    static Shell& getInstance() {
        static Shell instance;
        return instance;
    }

    void run();
    
private:
    Shell() {}; // Private constructor
    Shell(const Shell&) = delete; // Delete copy constructor
    Shell& operator=(const Shell&) = delete; // Delete copy assignment operator

    std::unordered_map<std::string, std::unique_ptr<ICommand>> commandMap;
    void registerCommand(const std::string& name, std::unique_ptr<ICommand> command);

    friend class Command;
};

}; // namespace shell
