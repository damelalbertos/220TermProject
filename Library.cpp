//
// Created by Matt on 11/26/2019.
//
#include "Library.h"

Library(Array* songs);

~Library();

Library(const Library& songCollectionToCopy);

Library& operator=(const Library& songCollectionToCopy);

void add(Song itemToAdd){
    allSongs.insertAtEnd(itemToAdd);
}

void remove(Song itemToRemove){
    int songIndex;
    songIndex = allSongs.find(itemToRemove);
    allSongs.removeValueAt(songIndex);
}

std::string printCollection(){
    allSongs.toString();
}

std::string getSong(){
}

std::string getArtist();

void saveCollection();

void loadCollection();