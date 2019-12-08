#include <iostream>

int main() {
    //UI STRING SET UP
    std::string command;
    std::string typeCommand = "Type a command or type help for a list of commands.";

    //PROGRAM
    std::cout << "Welcome to Auto DJ!" << std::endl;
    std::cout << typeCommand << std::endl;
    std::cin >> command;
    reactToCommand(command);
    return 0;
}

//test comment
//matts test