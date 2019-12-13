//
// Created by Matt on 12/12/2019.
//

#include "MasterTest.h"
#include "PlaylistCollectionTests.cpp"
#include "LibraryTests.cpp"
#include "FileTest.cpp"
#include "SongAndPlaylistTests.cpp"

void runAllTests(){
    runSongAndPlaylistTests();
    runPlaylistAndLibraryCollectionTests();
    runFileTests();
    //runLibraryTests();
}