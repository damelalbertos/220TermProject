//
// Created by Matt on 12/8/2019.
//
#include "Song.h"
#include "Playlist.h"
#include "Library.h"
#include <iostream>
//constructor test
void runSongTests(Song mySong1){
    std::cout << mySong1.toString() << std::endl;
    std::cout << mySong1.getArtist()<< std::endl;
    std::cout << mySong1.getTitle()<< std::endl;
    std::cout << mySong1.getDuration()<< std::endl;

    std::cout << mySong1.getPlayCount()<< std::endl;
    mySong1.addPlayCount();
    std::cout << mySong1.getPlayCount()<< std::endl;
    mySong1.addPlayCount();
    std::cout << mySong1.getPlayCount()<< std::endl;
    mySong1.clearPlayCount();
    std::cout << mySong1.getPlayCount()<< std::endl;

    std::cout << mySong1.toString() << std::endl;
    Song songCopy = mySong1;
    std::cout << songCopy.toString() << std::endl;

}

void enqueuePlaylistTest(Playlist testPlaylist){
    Song mySong1 =  Song("King Gizzard and the Lizard Wizard", "The spider and me", 193.2);
    Song* mySong1ptr = &mySong1;
    Song mySong2 =  Song("Led Zeppelin", "Stairway to Heaven", 481.8);
    Song* mySong2ptr = &mySong2;
    Song mySong3 =  Song("Lorde", "The Love Club", 202.2);
    Song* mySong3ptr = &mySong3;
    Song mySong4 =  Song("The Knocks", "No Requests", 190.8);
    Song* mySong4ptr = &mySong4;
    Song mySong5 =  Song("ASAP Ferg", "Work", 166.8);
    Song* mySong5ptr = &mySong5;


    testPlaylist.add(mySong1);
    testPlaylist.add(mySong2);
    testPlaylist.add(mySong3);
    testPlaylist.add(mySong4);
    testPlaylist.add(mySong5);

    testPlaylist.getSongCount();

    testPlaylist.printCollection();
    testPlaylist.played();
    testPlaylist.printCollection();

    testPlaylist.remove("The Knocks", "No Requests");
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
    Song mySong2 =  Song("Led Zeppelin", "Stairway to Heaven", 481.8);
    Song mySong3 =  Song("Lorde", "The Love Club", 202.2);
    Song mySong4 =  Song("The Knocks", "No Requests", 190.8);
    Song mySong5 =  Song("ASAP Ferg", "Work", 166.8);
    Song mySong6 =  Song("ASAP Ferg", "Worj", 166.8);
    if (mySong1 < mySong2){
        std::cout << "Pass" << std::endl;
    }
    if (mySong6 < mySong5){
        std::cout << "Pass" << std::endl;
    }

}