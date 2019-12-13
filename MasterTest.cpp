//
// Created by Matt on 12/12/2019.
//

#include "MasterTest.h"
#include "PlaylistCollectionTests.cpp"
#include "LibraryTests.cpp"
#include "FileTest.cpp"
#include "SongAndPlaylistTests.cpp"

void runAllTests(){
    std::cout << "(--------Running Song and Playlist Tests--------)" << std::endl;
    runSongAndPlaylistTests();
    std::cout << "(--------Running Playlist and Library Collection Tests--------)" << std::endl;
    runPlaylistAndLibraryCollectionTests();
    std::cout << "(--------Running File Tests--------)" << std::endl;
    runFileTests();
    std::cout << "(--------Running Library Tests--------)" << std::endl;
    runLibraryTests();
    //runLibraryTests();
}