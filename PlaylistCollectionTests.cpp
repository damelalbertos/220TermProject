//
// Created by Matt on 12/8/2019.
//
#include "PlaylistCollection.h"
#include "TestLib.h"

PlaylistCollection createPlaylistCollectionForTest(){
    Song mySong1 =  Song("King Gizzard and the Lizard Wizard", "The spider and me", 193.2);
    Song mySong2 =  Song("Led Zeppelin", "Stairway to Heaven", 481.8);
    Song mySong3 =  Song("Lorde", "The Love Club", 202.2);
    Song mySong4 =  Song("The Knocks", "No Requests", 190.8);
    Song mySong5 =  Song("ASAP Ferg", "Work", 166.8);

    Playlist testPlaylist1 = Playlist("testPlaylist");
    testPlaylist1.add(mySong1);
    testPlaylist1.add(mySong2);
    testPlaylist1.add(mySong3);

    Playlist testPlaylist2 = Playlist("testPlaylist2");
    testPlaylist2.add(mySong1);
    testPlaylist2.add(mySong2);
    testPlaylist2.add(mySong3);
    testPlaylist2.add(mySong4);

    Playlist testPlaylist3 = Playlist("testPlaylist3");
    testPlaylist3.add(mySong1);
    testPlaylist3.add(mySong2);
    testPlaylist3.add(mySong3);
    testPlaylist3.add(mySong4);
    testPlaylist3.add(mySong5);

    PlaylistCollection testPlaylistCollection;
    testPlaylistCollection.add(testPlaylist1);
    testPlaylistCollection.add(testPlaylist2);
    testPlaylistCollection.add(testPlaylist3);

    return testPlaylistCollection;

}


void playlistCollectionAddTests(){
    std::cout << "-----------AddTest----------" << std::endl;
    PlaylistCollection testCollection = createPlaylistCollectionForTest();


    testCollection.printCollection();


}


void playlistCollectionRemoveTest(){
    PlaylistCollection testCollection = createPlaylistCollectionForTest();
    Library testLib = Library();

    testLib.loadCollection("testSmall.txt");

    printAssertEquals(6,testLib.getCurrSongCount());

    std::cout << "Should be:\n"
              << "100 gecs\t745 sticky\t141.29\t0\n"
              << "100 gecs\tmoney machine\t114.46\t0\n"
              << "100 gecs\t800db cloud\t140.183\t0\n"
              << "2 Chainz\tForgiven (feat. Marsha Ambrosius)\t323.306\t0\n"
              << "2 Chainz\tThreat 2 Society\t225.8\t0\n"
              << "Aaron Copland\tDance Symphony: I. Dance of the Adolescent\t416.266\t0" << std::endl;

    testLib.printCollection();

}

void printCollectionTest(){
    PlaylistCollection testCollection = createPlaylistCollectionForTest();

    testCollection.printCollection();



}

void printAPlaylistTests(){
    PlaylistCollection testCollection = createPlaylistCollectionForTest();


}

void removeFromAllTests(){
    PlaylistCollection testCollection = createPlaylistCollectionForTest();

    Song mySong1 =  Song("King Gizzard and the Lizard Wizard", "The spider and me", 193.2);
    testCollection.removeFromAll(mySong1);



}

void saveCollectionTests(){
    PlaylistCollection testCollection = createPlaylistCollectionForTest();

}

int runPlaylistAndLibraryCollectionTests() {
    playlistCollectionAddTests();
    playlistCollectionRemoveTest();
    printCollectionTest();
    printAPlaylistTests();
    removeFromAllTests();
    saveCollectionTests();
    return 0;
}