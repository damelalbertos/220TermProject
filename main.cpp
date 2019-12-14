
//https://github.com/damelalbertos/220TermProject


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

    //todo each of the tests run well until memory issues are encountered
    std::cout << "---------File Tests---------" << std::endl;
    runFileTests();
    std::cout << "---------Library Tests---------" << std::endl;
    runLibraryTests();
    std::cout << "---------Song and Playlist Tests---------" << std::endl;
    runSongAndPlaylistTests();
    std::cout << "---------Playlist Collection Tests---------" << std::endl;
    runPlaylistCollectionTests();


    return 0;
}
