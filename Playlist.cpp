//
// Created by Matt on 11/26/2019.
//
#include "Playlist.h"

Playlist::Playlist(){
    this->playlistName = "";
    this->songsInPlaylist = new LinkedList<Song*>();
    this->duration = 0.0;
    this->songCount = 0;
}
//constructor
Playlist::Playlist(std::string playlistName){
    this->playlistName = playlistName;
    this->songsInPlaylist = new LinkedList<Song*>();
    this->duration = 0.0;
    this->songCount = 0;
}

//destructor
Playlist::~Playlist(){
    delete songsInPlaylist;
    songsInPlaylist = nullptr;
    duration = 0;
    songCount = 0;

}

std::string Playlist::getName(){
    return playlistName;
}

<<<<<<< HEAD

=======
>>>>>>> 2a5eee6917e256008a464bd759d61756a637c524
float Playlist::getDuration(){
    return duration;
}

int Playlist::getSongCount(){
    return songCount;
}

void Playlist::add(Song  songToAdd){
    Song* songPtr = &songToAdd;
    songsInPlaylist->insertAtEnd(songPtr);
    duration += songPtr->getDuration();
    songCount++;
}

std::string Playlist::played(){
    Song* songPlaying = songsInPlaylist->removeValueAtFront();
    songPlaying->addPlayCount();
    std::string songAsString = songPlaying->toString();
    return songAsString;
}

void Playlist::remove(std::string artistToRemove, std::string songToRemove){
    for(int i=0; i <= songCount; i++){
        Song* songToLookAt = songsInPlaylist->getValueAt(i);
        if(songToLookAt->getArtist() == artistToRemove && songToLookAt->getTitle() == songToRemove){
            songsInPlaylist->removeValueAt(i);
        }
    }

}

std::string Playlist::printCollection(){ // add playlistName parameter
    std::string playlistAsString;
    for(int i=0; i <= songCount; i++){
        Song* songToLookAt = songsInPlaylist->getValueAt(i);
        std::cout << songToLookAt->toString() << std::endl;
    }
    std::cout << "Duration left in playlist: " << getDuration() << std::endl;
}


void Playlist::saveCollection(){
    std::string filename = playlistName + ".txt";
    std::ofstream outf(filename);
    if (outf){
        for (int i = 0; i <= songCount; i++){
            Song* currentSong = songsInPlaylist->getValueAt(i);
            outf << currentSong->getArtist() << "\t" << currentSong->getTitle() << "\t" << (currentSong->getDuration() * 60000) << "\t" << currentSong->getPlayCount() << "\n";
        }
        outf.close();
    }

}

void Playlist::loadCollection(std::string filename){
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
                Song* newSongPtr = &newSong;
                if (songsInPlaylist->find(newSongPtr) == -1) {
                    add(newSong);
                }
            }
        }
    } else {
        std::cerr << "File not found." << std::endl;
    }
}

void Playlist::discontinuePlaylist(std::string filename) {
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
                Song* newSongPtr = &newSong;
                if (songsInPlaylist->find(newSongPtr) != -1) {
                    remove(newSongPtr->getArtist(), newSongPtr->getTitle());
                }
            }
        }

    }

}