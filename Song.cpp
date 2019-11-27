//
// Created by Matt on 11/18/2019.
//
#include "Song.h"

Song::Song(std::string artist, std::string title, float duration){
    this.artist = artist;
    this.title = title;
    this.duration = duration;
    this.playCount = 0;
}

Song::~Song();

Song::Song(const Song& songToCopy);

Song::Song& operator=(const Song& songToCopy);

std::string Song::getArtist();

std::string SOng::getTitle();

float Song::getDuration();

int Song::getPlayCount();

int Song::updatePlayCount(int num);
