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

std::string Library::getSong(std::string artistName, std::string songTitle){
    std::string returnStr;
    if (allSongs->isEmpty()){
        std::cerr << "Library is empty." << std::endl;
    }
    else {
        for (int i = 0; i < currSongCount; i++) {
            Song currentSong = allSongs->getValueAt(i);
            if (currentSong.getArtist() == artistName && currentSong.getTitle() == songTitle) {
                returnStr+=currentSong.toString();
                return returnStr;
            }
        }
        returnStr+= songTitle + " by " + artistName + " was not found in the library.";
    }
    return returnStr;
}

<<<<<<< HEAD
void Library::getArtist(std::string artistName){
=======
std::string Library::getArtist(std::string artistName){
    std::string returnStr;
>>>>>>> 8d50c9d7d4384ac9d38e4c97baf784fa597fc7bb
    for (int i = 0; i < currSongCount; i++){
        Song currentSong = allSongs->getValueAt(i);
        if (currentSong.getArtist() == artistName){
            returnStr += currentSong.toString();
        }
    }
<<<<<<< HEAD
    std::cerr << "No songs by " << artistName << " were found in the library." <<std::endl;
=======
    return returnStr;
>>>>>>> 8d50c9d7d4384ac9d38e4c97baf784fa597fc7bb
}

void Library::saveCollection(std::string filename){
    std::ofstream outf(filename);
    if (outf){
        for (int i = 0; i <= currSongCount; i++){
            Song currentSong = allSongs->getValueAt(i);
            outf << currentSong.getArtist() << "\t" << currentSong.getTitle() << "\t" << (currentSong.getDuration() * 1000) << "\t" << currentSong.getPlayCount() << "\n";
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
                float duration = stoi(song[2]) / 1000;
                Song newSong = Song(artist, name, duration);
                if ((getSong(artist,name) == newSong) == false) {
                    add(newSong);
                }
            }
        }
    } else {
        std::cerr << "File not found." << std::endl;
    }
}

void Library::discontinue(std::string filename, PlaylistCollection playlists) {
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
                float duration = stoi(song[2]) / 1000;
                Song newSong = Song(artist,name,duration);
                if (getSong(artist,name) == newSong) {
                    playlists.removeFromAll(getSong(artist,name));
                    remove(getSong(artist,name));
                }
            }
        }

    }

}
