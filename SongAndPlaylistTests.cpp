//
// Created by Matt on 12/8/2019.
//
#include "Song.h"
#include "Playlist.h"
#include "TestLib.h"
#include <iostream>
//constructor test
void runSongTests(Song mySong1){
    printAssertEquals("King Gizzard and the Lizard Wizard The spider and me", mySong1.toString());
    printAssertEquals("King Gizzard and the Lizard Wizard", mySong1.getArtist());
    printAssertEquals("The spider and me", mySong1.getTitle());
    std::cout << "The test is failing because of C++ rounding issues" << std::endl;
    printAssertEquals("193.2", std::to_string(mySong1.getDuration()));

    printAssertEquals(0, mySong1.getPlayCount());
    mySong1.addPlayCount();
    printAssertEquals(1, mySong1.getPlayCount());
    mySong1.addPlayCount();
    printAssertEquals(2, mySong1.getPlayCount());
    mySong1.clearPlayCount();
    printAssertEquals(0, mySong1.getPlayCount());

    printAssertEquals("King Gizzard and the Lizard Wizard The spider and me", mySong1.toString());
    Song songCopy = mySong1;
    printAssertEquals("King Gizzard and the Lizard Wizard The spider and me", songCopy.toString());

}

void enqueuePlaylistTest(){
    Playlist testPlaylist;
    Song mySong1 =  Song("King Gizzard and the Lizard Wizard", "The spider and me", 193.2);
    Song mySong2 =  Song("Led Zeppelin", "Stairway to Heaven", 481.8);
    Song mySong3 =  Song("Lorde", "The Love Club", 202.2);
    Song mySong4 =  Song("The Knocks", "No Requests", 190.8);
    Song mySong5 =  Song("ASAP Ferg", "Work", 166.8);


    testPlaylist.add(mySong1);
    testPlaylist.add(mySong2);
    testPlaylist.add(mySong3);
    testPlaylist.add(mySong4);
    testPlaylist.add(mySong5);

    printAssertEquals(5,testPlaylist.getSongCount());

    std::cout << "\n\n\nTest2\n"
              << "Should be:\n"
              << "King Gizzard and the Lizard Wizard The spider and me\n"
              << "Led Zeppelin Stairway to Heaven\n"
              << "Lorde The Love Club\n"
              << "The Knocks No Requests\n"
              << "ASAP Ferg Work\n"  << std::endl;
    testPlaylist.printCollection();
    testPlaylist.played();
    std::cout << "\n\n\nTest3\n"
              << "Should be:\n"
              << "Led Zeppelin Stairway to Heaven\n"
              << "Lorde The Love Club\n"
              << "The Knocks No Requests\n"
              << "ASAP Ferg Work\n"  << std::endl;
    testPlaylist.printCollection();

    testPlaylist.remove("The Knocks", "No Requests");
    std::cout << "\n\n\nTest4\n"
              << "Should be:\n"
              << "Led Zeppelin Stairway to Heaven\n"
              << "Lorde The Love Club\n"
              << "ASAP Ferg Work\n"  << std::endl;
    testPlaylist.printCollection();
}

void nameAndDurationPlaylistTests(Playlist testPlaylist){
    std::cout << testPlaylist.getName() << std::endl;
    //iterate through songs then add up
    for(int i=0; i <= testPlaylist.getSongCount(); i++){

    }
    std::cout << testPlaylist.getDuration() << std::endl;
}


//copy constructor test

//assignment operator test

//destructor test

//get artist test

//get title test

//get duration test

//add to play count test

//clear play count test

int runSongAndPlaylistTests(){
    Song mySong1 =  Song("King Gizzard and the Lizard Wizard", "The spider and me", 193.2);
    runSongTests(mySong1);
    enqueuePlaylistTest();

}