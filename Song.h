//
// Created by Matt on 11/18/2019.
//

#ifndef FINAL_PROJECT_SONG_H
#define FINAL_PROJECT_SONG_H

class Song{

private:
    std::string artist;
    std::string title;
    float duration;
    int playCount;

public:

    //constructor, copy constructor, assignment operator, destructor
    Song(std::string artist, std::string title, float duration);

    ~Song();

    Song(const Song& songToCopy);

    Song& operator=(const Song& songToCopy);


    //getters
    std::string getArtist();

    std::string getTitle();

    float getDuration();

    int getPlayCount();


    //executables



};


#endif //FINAL_PROJECT_SONG_H
