//
// Created by Damel Albertos on 12/5/19.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include "UserInterface.h"


UserInterface::UserInterface() {
}

bool compareChar(char & c1, char & c2){
    if (c1 == c2)
        return true;
    else if (std::toupper(c1) == std::toupper(c2))
        return true;
    return false;
}

bool caseInSensStringCompare(std::string & str1, std::string &str2) {
    return ((str1.size() == str2.size()) &&
            std::equal(str1.begin(), str1.end(), str2.begin(), &compareChar));
}

void UserInterface::reactToCommand(std::string command){
    std::string help = "help";
    std::string library = "library";
    std::string artist = "artist";
    std::string song = "song";
    std::string import = "import";
    std::string discontinue = "discontinue";
    std::string playlists = "playlists";
    std::string playlist = "playlist";
    std::string neW = "new";
    std::string add = "add";
    std::string remove = "remove";
    std::string next = "next";
    std::string random = "random";
    std::string quit = "quit";

    bool helpCheck = caseInSensStringCompare(help, command);
    bool libraryCheck = caseInSensStringCompare(library, command);
    bool artistCheck = caseInSensStringCompare(artist, command);
    bool songCheck = caseInSensStringCompare(song, command);
    bool importCheck = caseInSensStringCompare(import, command);
    bool discontinueCheck = caseInSensStringCompare(discontinue, command);
    bool playlistsCheck = caseInSensStringCompare(playlists, command);
    bool playlistCheck = caseInSensStringCompare(playlist, command);
    bool newCheck = caseInSensStringCompare(neW, command);
    bool addCheck = caseInSensStringCompare(add, command);
    bool removeCheck = caseInSensStringCompare(remove, command);
    bool nextCheck = caseInSensStringCompare(next, command);
    bool randomCheck = caseInSensStringCompare(random, command);
    bool quitCheck = caseInSensStringCompare(quit, command);

    if (helpCheck){
        this->help();
    } else if (libraryCheck){
        this->library();
    } else if (artistCheck){
        std::string artistSelection;
        std::cout << "What artist?" << std::endl;
        std::cin >> artistSelection;
        this->artistSongs(artistSelection);
    } else if (songCheck){
        std::string artistSelection;
        std::string songTitle;
        std::cout << "What artist?" << std::endl;
        std::cin >> artistSelection;
        std::cout << "What song?" << std::endl;
        std::cin >> songTitle;
        this->songInfo(artistSelection, songTitle);
    } else if (importCheck){
        std::string filename;
        std::cout << "Please type the filename." << std::endl;
        std::cin >> filename;
        this->import(filename);
    } else if (discontinueCheck){
        std::string filename;
        std::cout << "Please type the filename." << std::endl;
        std::cin >> filename;
        this->discontinue(filename);
    } else if (playlistsCheck){
        this->allPlaylists();
    } else if (playlistCheck){
        std::string playlistName;
        std::cout << "What is the playlist name?" << std::endl;
        std::cin >> playlistName;
        this->playlistInfo(playlistName);
    } else if (newCheck){
        std::string playlistName;
        std::cout << "What would you like to call the playlist?" << std::endl;
        std::cin >> playlistName;
        this->newPlaylist(playlistName);
    } else if (addCheck){
        std::string songName;
        std::string artistName;
        std::string sDuration;
        std::string playlistName;
        std::cout << "What is the song name?" << std::endl;
        std::cin >> songName;
        std::cout << "What is the artist's name?" << std::endl;
        std::cin >> artistName;
        std::cout << "What is the duration of the song?" << std::endl;
        std::cin >> sDuration;
        std::cout << "Which playlist would you like to add this song to?" << std::endl;
        std::cin >> playlistName;
        int duration = stoi(sDuration);
        this->addSong(songName,artistName,duration,playlistName);
    } else if (removeCheck){
        std::string songName;
        std::string artistName;
        std::string playlistName;
        std::cout << "What is the song name?" << std::endl;
        std::cin >> songName;
        std::cout << "What is the artist's name?" << std::endl;
        std::cin >> artistName;
        std::cout << "Which playlist would you like to remove this song from?" << std::endl;
        std::cin >> playlistName;
        this->removeSong(songName,artistName,playlistName);
    } else if (nextCheck){
        std::string playlistName;
        std::cout << "What is the playlist name?" << std::endl;
        std::cin >> playlistName;
        this->playNext(playlistName);
    } else if (randomCheck){
        std::string playlistName;
        std::string sDuration;
        int duration;
        std::cout << "What would you like the playlist to be called?" << std::endl;
        std::cin >> playlistName;
        std::cout << "What would you like the duration to be?" << std::endl;
        std::cin >> sDuration;
        duration = stoi(sDuration);
        this->newRandom(playlistName,duration);
    } else if (quitCheck){
        std::string filename;
        std::cout << "Please type the filename to save your library and playlists." << std::endl;
        std::cin >> filename;
        this->quit(filename);
    }
}

void UserInterface::help() {
    std::cout << "help: Summary of available commands." << std::endl;
    std::cout << "library: Display of all songs in library." << std::endl;
    std::cout << "artist: Display all songs by given artist." << std::endl;
    std::cout << "song: Display all information about a given song." << std::endl;
    std::cout << "import: Import file of songs, to be added to library." << std::endl;
    std::cout << "discontinue: Remove all songs from library and playlists found on file." << std::endl;
    std::cout << "playlists: Display all playlists and their durations." << std::endl;
    std::cout << "playlist songs: Display all songs left and the duration of a given playlist." << std::endl;
    std::cout << "new: Create a new empty playlist." << std::endl;
    std::cout << "add: Add a song to a playlist." << std::endl;
    std::cout << "remove: Remove a song from a playlist." << std::endl;
    std::cout << "next: Display info on next song in a playlist." << std::endl;
    std::cout << "random: Create a new playlist that populates with random songs from library." << std::endl;
    std::cout << "quit: Save the library/playlists and terminate program." << std::endl;
}

void UserInterface::library() {
    Library lib = Library();
    lib.printCollection();
}

void UserInterface::artistSongs(std::string artist, Library lib) {
    lib.getArtist(artist);
}

void UserInterface::songInfo(std::string artist, std::string songTitle, Library lib) {
    Song newSong = lib.getSong(artist,songTitle);

}

void UserInterface::import(std::string filename, Library lib) {
    lib.loadCollection(filename);
}

void UserInterface::discontinue(std::string filename, Library lib, PlaylistCollection p1) {
    p1.discontinuePlaylists(filename);
    lib.discontinueLib(filename);
}

void UserInterface::allPlaylists(PlaylistCollection pl) {
    pl.printCollection();
}

void UserInterface::playlistInfo(std::string playlistName, PlaylistCollection pl) {
    pl.printAPlaylist(playlistName);
}

void UserInterface::newPlaylist(std::string playlistName, PlaylistCollection pl) {
    Playlist newPl = Playlist(playlistName);
    pl.add(playlistName);
}

void UserInterface::addSong(std::string songName, std::string artistName, int duration, std::string playlistName, Playlist pl, Library lib) {
    Song newSong = Song(artistName, songName, duration);
    if (lib.getCollection()->find(newSong) != -1) {
        pl.add(lib.getSong(artistName,songName));
    }
}
//todo
void UserInterface::removeSong(std::string songName, std::string artistName, std::string playlistName, PlaylistCollection p1) {
    Playlist playlistToRemoveFrom = p1.;
    pl.remove(artistName, songName);
}
//todo
void UserInterface::playNext(std::string playlistName) {
    Playlist pl = Playlist(playlistName);
    pl.played();
}

void UserInterface::newRandom(std::string playlistName, int duration, Library lib) {
    PlaylistCollection pl = PlaylistCollection();
    pl.genRandPlaylist(playlistName, duration, lib);
}

void UserInterface::quit(std::string filename) {
    PlaylistCollection pl = PlaylistCollection();
    Library lib = Library();
    pl.saveCollection(filename);
    lib.saveCollection(filename);
}