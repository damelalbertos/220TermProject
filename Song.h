//
// Created by Matt on 11/18/2019.
//

#ifndef FINAL_PROJECT_SONG_H
#define FINAL_PROJECT_SONG_H

#include<string>
#include "ArrayList.h"

class Song{

private:
    std::string artist;
    std::string title;
    float duration;
    int playCount;

public:

    //constructor, copy constructor, assignment operator
    Song(std::string artist, std::string title, float duration);


    Song(const Song& songToCopy);

    bool operator==(const Song& songToCopy){
        if(artist == songToCopy.artist && title == songToCopy.title){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator>(const Song& songToCopy){
        std::string song1 = artist + title;
        std::string song2 = songToCopy.artist + songToCopy.title;

        int result = song1.compare(song2);

        if(result > 0){
            return true;
        }
        else{
            return false;
        }

    }

    bool operator<(const Song& songToCopy){
        std::string song1 = artist + title;
        std::string song2 = songToCopy.artist + songToCopy.title;

        int result = song1.compare(song2);

        if(result > 0){
            return false;
        }
        else{
            return true;
        }
    }

    //getters
    std::string getArtist();

    std::string getTitle();

    float getDuration();

    int getPlayCount();

    //executables
    void addPlayCount();

    void clearPlayCount(int num);

    std::string toString();


};


#endif //FINAL_PROJECT_SONG_H
