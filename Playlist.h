//
// Created by Matt on 11/26/2019.
//

#ifndef PROJECT_PLAYLIST_H
#define PROJECT_PLAYLIST_H

class Playlist : Public MusicCollection{

private:
    std::string playlistName;
    LinkedQueue* songList;
    float duration;
    int songCount;
    int playlistPlayCount;

public:

    Playlist(std::string playlistName, LinkedQueue* songList, float duration, int songCount);

    ~Playlist();

    Playlist(const Playlist& playlistToCopy);

    Platlist& operator=(const Playlist& playlistToCopy);

    std::string getPlaylistName();

    float getDuration();

    int getSongCount();

    int getPlayCount();

    void add(Song songToAdd);

    void remove(Song songToRemove);

    std::string printCollection();

    void saveCollection();

    void loadCollection();

};

#endif //PROJECT_PLAYLIST_H
