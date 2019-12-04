//
// Created by Damel Albertos on 12/4/19.
//

#ifndef TERM_PROJECT_USERINTERFACE_H
#define TERM_PROJECT_USERINTERFACE_H
#include<string>

class UserInterface {
private:
    int* commands;
    int playCount;

public:
    UserInterface();

    void help();
    void library();
    void artistSongs(std::string artist);
    void songInfo(std::string artist, std::string songTitle);
    void import(std::string filename);
    void discontinue(std::string filename);
    void allPlaylistInfo();
    void playlistInfo(std::string playlistName);
    void newPlaylist(std::string playlistName);
    void addSong(std::string songName, std::string artistName, std::string songTitle);
    void removeSong(std::string songName, std::string artistName, std::string songTitle);
    void playNext(std::string name);
    void newRandom(std::string playlistName, int duration);
    void quit();

};

#endif //TERM_PROJECT_USERINTERFACE_H
