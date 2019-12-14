//
// Created by Matt on 11/26/2019.
//
#include "Library.h"


Library::Library(){
    allSongs = new ArrayList<Song>(10);
    currSongCount = 0;
    currCapacity = 10;
}

Library::~Library(){

}

Library::Library(const Library& songCollectionToCopy){

}

ArrayList<Song>* Library::getCollection(){
    return allSongs;
}

int Library::getCurrCapacity() {
    return currCapacity;
}

int Library::getCurrSongCount() {
    return currSongCount;
}

void Library::add(Song itemToAdd){
    allSongs->insertAtEnd(itemToAdd);
}


void Library::remove(Song itemToRemove){
    int songIndex;
    songIndex = allSongs->find(itemToRemove);
    allSongs->removeValueAt(songIndex);
}


void Library::printCollection(){
    if (currSongCount == 0){
        std::cout << "The library is empty." << std::endl;
    }

    else {

        std::cout << "Artist:\tTitle:\tDuration (seconds):\tPlay Count:";
        for (int i = 0; i <= currSongCount; i++) {
            Song currentSong = allSongs->getValueAt(i);
            std::cout << currentSong.getArtist() << "\t" << currentSong.getTitle() << "\t" << currentSong.getDuration()
                      << "\t" << currentSong.getPlayCount() << std::endl;

        }
    }
}

Song Library::getSong(std::string artistName, std::string songTitle){
    if (currSongCount == 0){
        throw std::invalid_argument("Library is empty.");
    }
    for (int i = 0; i < currSongCount; i++) {
        Song currentSong = allSongs->getValueAt(i);
        if (currentSong.getArtist() == artistName && currentSong.getTitle() == songTitle) {
            std::cout << currentSong.toString() << std::endl;
            return currentSong;
        }
    }
    throw std::invalid_argument(songTitle + " by " + artistName + " was not found in the library.");

}

void Library::getArtist(std::string artistName){
    for (int i = 0; i < currSongCount; i++){
        Song currentSong = allSongs->getValueAt(i);
        if (currentSong.getArtist() == artistName){
            std::cout << currentSong.toString() << std::endl;
        }
    }
    throw std::invalid_argument("No songs by " + artistName + " were found in the library.");
}

void Library::saveCollection(std::string filename){
    std::ofstream outf(filename);
    if (outf){
        for (int i = 0; i <= currSongCount; i++){
            Song currentSong = allSongs->getValueAt(i);
            outf << currentSong.getArtist() << "\t" << currentSong.getTitle() << "\t" << (currentSong.getDuration() * 60000) << "\t" << currentSong.getPlayCount() << "\n";
        }
        outf.close();
    }
}

void Library::loadCollection(std::string filename) {
    std::ifstream infile(filename);
    if (infile) {
        while (infile) {
            std::string strInput;
            getline(infile, strInput);
            if (strInput != "") {
                int size = countChar(strInput, '\t') + 1;
                std::string *song = toList(strInput, size);
                std::string artist = song[0];
                std::string name = song[1];
                float duration = stoi(song[2]) / 60000;
                Song newSong = Song(artist, name, duration);
                if (allSongs->find(newSong) == -1) {
                    add(newSong);
                }
            }
        }
    } else {
        std::cerr << "File not found." << std::endl;
    }
}

void Library::discontinueLib(std::string filename) {
    std::ifstream infile(filename);
    if (infile) {
        while (infile) {
            std::string strInput;
            getline(infile, strInput);
            if (strInput != "") {
                int size = countChar(strInput, '\t') + 1;
                std::string *song = toList(strInput, size);
                std::string artist = song[0];
                std::string name = song[1];
                float duration = stoi(song[2]) / 60000;
                Song newSong = Song(artist,name,duration);
                if (allSongs->find(newSong) != -1) {
                    remove(getSong(artist,name));
                }
            }
        }

    }

}
