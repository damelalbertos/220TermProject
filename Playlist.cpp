//
// Created by Matt on 11/26/2019.
//
#include "Playlist.h"


//constructor
Playlist::Playlist(std::string playlistName){
    this->playlistName = playlistName;
    this->songsInPlaylist = new LinkedList<Song*>();
    this->duration = 0.0;
    this->songCount = 0;
}

//destructor
Playlist::~Playlist(){
    songsInPlaylist->removeValueAtFront();
    delete songsInPlaylist;
}

std::string Playlist::getName(){
    return playlistName;
}

float Playlist::getDuration(){
    return duration;
}

int Playlist::getSongCount(){
    return songCount;
}

void Playlist::add(Song* songToAdd){
    songsInPlaylist->insertAtEnd(songToAdd);
    duration += songToAdd->getDuration();
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

std::string Playlist::printCollection(){
    std::string playlistAsString;
    for(int i=0; i <= songCount; i++){
        Song* songToLookAt = songsInPlaylist->getValueAt(i);
        std::cout << songToLookAt->toString() << std::endl;
    }
    std::cout << "Duration left in playlist: " << getDuration() << std::endl;
}

//todo
void Playlist::saveCollection(){

}

//todo
void Playlist::loadCollection(){

}