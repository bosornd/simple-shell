# Simple Shell

This project is a simple shell implementation in C++. It allows users to execute commands, handle input/output redirection, and manage background processes.

## Class Diagram
```mermaid
classDiagram
namespace shell {
    class ICommand {
        +bool execute(const std::istringstream& args)
    }

    class Command {
        +template ~typename T~ static void registerCommand(const std::string& name)
    }

    class Shell {
        +static Shell& getInstance()
        +void run()
        -void registerCommand(const std::string& name, std::unique_ptr~ICommand~ command)
        friend class Command
        -std::unordered_map&lt;std::string, std::unique_ptr~ICommand~&gt; commandMap
    }
}

namespace command {
    class HelpCommand {
        +bool execute(const std::istringstream& args)
    }

    class ExitCommand {
        +bool execute(const std::istringstream& args)
    }   
}

    Shell --> ICommand
    ICommand <|-- Command
    Command <|-- HelpCommand
    Command <|-- ExitCommand
```

## Usage

1. Clone the repository:
    ```sh
    git clone <repository-url>
    cd simple-shell
    ```

2. Compile the source code:
    ```sh
    make
    ```

3. Run the shell:
    ```sh
    ./simple-shell
    ```

## License

This project is licensed under the MIT License.
