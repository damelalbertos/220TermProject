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

    Song(std::string artist, std::string title, float duration, int playCount);

    ~Song();

    Song(const Song& songToCopy);

    Song& operator=(const Song& songToCopy);

    std::string getArtist();

    std::string getTitle();

    float getDuration();

    int getPlayCount();

    int updatePlayCount(int num);



};


#endif //FINAL_PROJECT_SONG_H
