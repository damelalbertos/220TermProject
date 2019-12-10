//
// Created by Matt on 11/18/2019.
//

#ifndef FINAL_PROJECT_SONG_H
#define FINAL_PROJECT_SONG_H

#include<string>

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
