#include <iostream>
#include "UserInterface.h"

int main() {
    //UI SET UP
    UserInterface* user = new UserInterface();
    std::string command;
    std::string typeCommand = "Type a command or type help for a list of commands.";

    //PROGRAM
    std::cout << "Hi! Would you like to Test your code or start Auto DJ?" << std::endl;
    std::cout << "Type ""Test"" or ""DJ""." << std::endl;
    std::cin >> command;
    if (command == "Test" || command == "test"){
        //runtests()
    }
    else{
        std::cout << "Welcome to Auto DJ!" << std::endl;
        std::cout << typeCommand << std::endl;
        std::cin >> command;
        user->reactToCommand(command);
    }
    return 0;
}

//test comment
//matts test