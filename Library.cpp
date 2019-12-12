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

Library::Library& operator=(const Library& songCollectionToCopy){

}

void Library::add(Song itemToAdd){
    allSongs->insertAtEnd(itemToAdd);
}


void Library::remove(Song itemToRemove){
    int songIndex;
    songIndex = allSongs->find(itemToRemove);
    allSongs->removeValueAt(songIndex);
}

//todo
void Library::printCollection(){
    //todo if empty
    if (currSongCount == 0){
        std::cout << "The library is empty." << std::endl;
    }

    else {

        std::cout << "Artist:\tTitle:\tDuration (seconds):\tPlay Count:";
        for (int i = 0; i <= currSongCount; i++) {
            Song currentSong = allSongs[i];
            std::cout << currentSong.getArtist() << "\t" << currentSong.getTitle() << "\t" << currentSong.getDuration()
                      << "\t" << currentSong.getPlayCount() << std::endl;

        }
    }
}

//todo
std::string Library::getSong(std::string artistName, std::string songTitle){

}

//todo
std::string Library::getArtist(std::string artistName){

}

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
    std::ifstream infile(filename);
    if (infile) {
        while (infile) {
            std::string strInput;
            getline(infile, strInput);
            if (strInput != "") {
                int size = countChar(strInput, '\t') + 1;
                std::string* song = toList(strInput, size);
                std::string artist = song[0];
                std::string name = song[1];
                float duration = stoi(song[2]) / 1000;
                Song newSong = Song(artist, name, duration);
                add(newSong);
            }
        }
    }

    else {
        std::cerr << "File not found." << std::endl;
    }
}
