//
// Created by Matt on 11/26/2019.
//
#include "Playlist.h"


//constructor
Playlist::Playlist(std::string playlistName){
    this->playlistName = playlistName;
    this->songsInPlaylist = new LinkedQueue<Song*>();
    this->duration = 0.0;
    this->songCount = 0;
}

//destructor
Playlist::~Playlist(){
    songsInPlaylist->dequeue();
    delete songsInPlaylist;
}

//todo
//copy constructor
Playlist::Playlist(const Playlist& playlistToCopy){

}

//todo
//assignment operator
Playlist::Playlist& operator=(const Playlist& playlistToCopy){

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
    songsInPlaylist->enqueue(songToAdd);
    duration += songToAdd->getDuration();
    songCount++;
}

std::string Playlist::played(){
    Song* songPlaying = songsInPlaylist->dequeue();
    songPlaying->addPlayCount();
    std::string songAsString = songPlaying->toString();
    return songAsString;
}

//todo
void Playlist::remove(std::string artistToRemove, std::string songToRemove){
    for(int i=0; i <= songCount; i++){
        Song songToLookAt = songsInPlaylist->

    }
}

std::string Playlist::printPlaylist(){
    std::string playlistAsString;
    for(int i=0; i <= songCount; i++){
        playlistAsString += songsInPlaylist->
    }
}

//todo
void Playlist::saveCollection();

//todo
void Playlist::loadCollection();