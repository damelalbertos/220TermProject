//
// Created by Matt on 12/8/2019.
//
#include "Song.h"
#include "Playlist.h"
#include "TestLib.h"
#include <iostream>
//constructor test
void runSongTests(Song mySong1){
    std::cout << "The tests failing are because of C++ rounding issues" << std::endl;
    printAssertEquals("King Gizzard and the Lizard WizardThe spider and me", mySong1.toString());
    printAssertEquals("King Gizzard and the Lizard Wizard", mySong1.getArtist());
    printAssertEquals("The spider and me", mySong1.getTitle());
    printAssertEquals("193.2", std::to_string(mySong1.getDuration()));

    printAssertEquals(0, mySong1.getPlayCount());
    mySong1.addPlayCount();
    printAssertEquals(1, mySong1.getPlayCount());
    mySong1.addPlayCount();
    printAssertEquals(2, mySong1.getPlayCount());
    mySong1.clearPlayCount();
    printAssertEquals(0, mySong1.getPlayCount());

    printAssertEquals("King Gizzard and the Lizard WizardThe spider and me", mySong1.toString());
    Song songCopy = mySong1;
    printAssertEquals("King Gizzard and the Lizard WizardThe spider and me", songCopy.toString());

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

    std::cout << "Should be:\n"
              << "King Gizzard and the Lizard WizardThe spider and me\n"
              << "Led ZeppelinStairway to Heaven\n"
              << "LordeThe Love Club\n"
              << "The KnocksNo Requests\n"
              << "ASAP FergWork"  << std::endl;
    testPlaylist.printCollection();
    testPlaylist.played();
    std::cout << "Should be:\n"
              << "Led ZeppelinStairway to Heaven\n"
              << "LordeThe Love Club\n"
              << "The KnocksNo Requests\n"
              << "ASAP FergWork"  << std::endl;
    testPlaylist.printCollection();

    testPlaylist.remove("The Knocks", "No Requests");
    std::cout << "Should be:\n"
              << "King Gizzard and the Lizard WizardThe spider and me\n"
              << "Led ZeppelinStairway to Heaven\n"
              << "LordeThe Love Club\n"
              << "ASAP FergWork"  << std::endl;
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