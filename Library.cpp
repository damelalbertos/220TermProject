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

//todo
void remove(Song itemToRemove){
    int songIndex;
    songIndex = allSongs.find(itemToRemove);
    allSongs.removeValueAt(songIndex);
}

//todo
std::string printCollection(){
    allSongs.toString();
}

//todo
std::string getSong(){
}

//todo
std::string getArtist();

//todo
void saveCollection();

//todo
void loadCollection();