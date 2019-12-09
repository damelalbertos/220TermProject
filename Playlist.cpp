//
// Created by Matt on 11/26/2019.
//
#include "Playlist.h"


//constructor
Playlist::Playlist(std::string playlistName){
    playlistName = playlistName;
    front = nullptr;
    end = nullptr;
    duration = 0.0;
    songCount = 0;
}

//destructor
Playlist::~Playlist();

//copy constructor
Playlist::Playlist(const Playlist& playlistToCopy);

//assignment operator
Playlist::Playlist& operator=(const Playlist& playlistToCopy);

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
    LinkedNode* newNode = new LinkedNode(songToAdd);
    if (front == nullptr){
        front = newNode;
        end = newNode;
        duration += songToAdd*.getDuration();
        songCount++;
    }
    else {
        end->setNext(newNode);
        end = newNode;
        duration += songToAdd*.getDuration();
        songCount++;
    }
}

void Playlist::played(){
    if(front == nullptr){
        throw std::out_of_range("Playlist is empty");
    }
    else if(front == end){
        std::string songInfo = front->getItem()*.toString();
        delete front;
        front = nullptr;
        end = nullptr;
        return songInfo;
    }
    else{
        std::string songInfo = front->getItem()*.toString();
        LinkedNode* tempPtr = front->getNext();

        delete front;

        front = tempPtr;
        return songInfo;
    }
}

//todo
void Playlist::remove(Song songToRemove);


std::string Playlist::printCollection(){
    std::string playlistAsString;
    for(int i=0; i <= songCount; i++){
        playlistAsString += front->getItem().toString();
        playlistAsString += "\n";
    }
    return playlistAsString;
}

//todo
void Playlist::saveCollection();

//todo
void Playlist::loadCollection();