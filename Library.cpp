//
// Created by Matt on 11/26/2019.
//
#include "Library.h"
#include "Song.h"

Library::Library(){
    allSongs = new ArrayList<Song>(10);
    currSongCount = 0;
    currCapacity = 10;
}

Library::~Library();

Library::Library(const Library& songCollectionToCopy);

Library::Library& operator=(const Library& songCollectionToCopy);

void Library::add(Song itemToAdd){
    allSongs.insertAtEnd(itemToAdd);
}

//todo
void Library::remove(Song itemToRemove){
    int songIndex;
    songIndex = allSongs.find(itemToRemove);
    allSongs.removeValueAt(songIndex);
}

//todo
std::string Library::printCollection(){
    std::string libraryAsString;
    for(int i=0; i <= currSongCount; i++){
        allSongs
    }
}

//todo
std::string Library::getSong(){
}

//todo
std::string Library::getArtist();

//todo
void Library::saveCollection();

//todo
void Library::loadCollection();