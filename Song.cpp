//
// Created by Matt on 11/18/2019.
//
#include "Song.h"

Song::Song(std::string artist, std::string title, float duration){
    artist = artist;
    title = title;
    duration = duration;
    playCount = 0;
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

void Song::addPlayCount(int num){
    playCount++;
}

void Song::clearPlayCount(int num){
    playCount = 0;
}

