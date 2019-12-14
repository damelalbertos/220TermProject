#include <iostream>
#include "PlaylistCollectionTests.cpp"
#include "LibraryTests.cpp"
#include "FileTest.cpp"
#include "SongAndPlaylistTests.cpp"

int main(){
    /**
    //UI SET UP
    UserInterface* user = new UserInterface();
    std::string command;
    std::string typeCommand = "Type a command or type help for a list of commands.";

    //PROGRAM
    std::cout << "Hi! Would you like to Test your code or start Auto DJ?" << std::endl;
    std::cout << "Type ""Test"" or ""DJ""." << std::endl;
    if (command == "Test" || command == "test"){
        runAllTests();
    }
    else{
        std::cout << "Welcome to Auto DJ!" << std::endl;
    }
    while (command != "quit"){
        std::cout << typeCommand << std::endl;
        std::cin >> command;
        user->reactToCommand(command);
    }
    */
    //runSongAndPlaylistTests();
    std::cout << "---------File Tests---------" << std::endl;
    runFileTests();
    std::cout << "---------Library Tests---------" << std::endl;
    runLibraryTests();
    runPlaylistCollectionTests();


    return 0;
}
