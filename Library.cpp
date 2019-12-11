//
// Created by Matt on 11/26/2019.
//
#include "Library.h"
#include "Song.h"
#include "File.h"

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
void Library::printCollection(){
    //todo if empty



    std::cout << "Artist:\tTitle:\tDuration (seconds):\tPlay Count:";
    for(int i=0; i <= currSongCount; i++){
        Song currentSong = allSongs[i];
        std::cout << currentSong.getArtist() << "\t" << currentSong.getTitle() << "\t" << currentSong.getDuration() << "\t" << currentSong.getPlayCount() << std::endl;

    }
}

//todo
std::string Library::getSong(){
}

//todo
std::string Library::getArtist();

void Library::saveCollection(std::string filename){
    std::ofstream outf(filename);
    if (outf){
        for (int i = 0; i <= currSongCount; i++){
            Song currentSong = allSongs[i];
            outf << currentSong.getArtist() << "\t" << currentSong.getTitle() << "\t" << currentSong.getDuration() << "\t" << currentSong.getPlayCount() << std::endl;
        }
        outf.close();
    }
}

void Library::loadCollection(std::string filename){
    load_library(filename);
}