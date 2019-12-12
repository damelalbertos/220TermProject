//
// Created by Matt on 11/18/2019.
//
#include "Song.h"

Song::Song(){
    this->artist = "";
    this->title = "";
    this->duration = 0.0;
    this->playCount = 0;
}

Song::Song(std::string artist, std::string title, float duration){
    this->artist = artist;
    this->title = title;
    this->duration = duration;
    this->playCount = 0;
}


Song::Song(const Song& songToCopy){
    artist = songToCopy.artist;
    title = songToCopy.title;
    duration = songToCopy.duration;
    playCount = songToCopy.playCount;
}


std::string Song::getArtist(){
    return artist;
}

std::string Song::getTitle(){
    return title;
}

float Song::getDuration(){
    return duration;
}

int Song::getPlayCount(){
    return playCount;
}

void Song::addPlayCount(){
    playCount++;
}

void Song::clearPlayCount(){
    playCount = 0;
}

std::string Song::toString(){
    std::string songAsString;
    songAsString += artist;
    songAsString += title;
    songAsString += std::to_string(duration);
    songAsString += std::to_string(playCount);
    return songAsString;
}
