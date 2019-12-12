//
// Created by Damel Albertos on 12/5/19.
//

#include <iostream>
#include <cstdlib>
#include "UserInterface.h"
#include "Library.h"
#include "PlaylistCollection.h"
#include "Playlist.h"

UserInterface::UserInterface() {
}

void UserInterface::reactToCommand(std::string command) {
    if (command == "help"){
        help();
    } else if (command == "library"){
        library();
    } else if (command == "artist songs"){
        std::string artistSelection;
        std::cout << "What artist?" << std::endl;
        std::cin >> artistSelection;
        artistSongs(artistSelection);
    } else if (command == "song info"){
        std::string artistSelection;
        std::string songTitle;
        std::cout << "What artist?" << std::endl;
        std::cin >> artistSelection;
        std::cout << "What song?" << std::endl;
        std::cin >> songTitle;
        songInfo(artistSelection, songTitle);
    } else if (command == "import"){
        std::string filename;
        std::cout << "Please type the filename." << std::endl;
        std::cin >> filename;
        import(filename);
    } else if (command == "discontinue"){
        std::string filename;
        std::cout << "Please type the filename." << std::endl;
        std::cin >> filename;
        discontinue(filename);
    } else if (command == "playlists"){
        allPlaylists();
    } else if (command == "playlist songs"){
        std::string playlistName;
        std::cout << "What is the playlist name?" << std::endl;
        std::cin >> playlistName;
        playlistInfo(playlistName);
    } else if (command == "new playlist"){
        std::string playlistName;
        std::cout << "What would you like to call the playlist?" << std::endl;
        std::cin >> playlistName;
        newPlaylist(playlistName);
    } else if (command == "add song"){
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
        addSong(songName,artistName,duration,playlistName);
    } else if (command == "remove song"){
        std::string songName;
        std::string artistName;
        std::string playlistName;
        std::cout << "What is the song name?" << std::endl;
        std::cin >> songName;
        std::cout << "What is the artist's name?" << std::endl;
        std::cin >> artistName;
        std::cout << "Which playlist would you like to remove this song from?" << std::endl;
        std::cin >> playlistName;
        removeSong(songName,artistName,playlistName);
    } else if (command == "play next"){
        std::string playlistName;
        std::cout << "What is the playlist name?" << std::endl;
        std::cin >> playlistName;
        playNext(playlistName);
    } else if (command == "new random"){
        std::string playlistName;
        std::string sDuration;
        int duration;
        std::cout << "What would you like the playlist to be called?" << std::endl;
        std::cin >> playlistName;
        std::cout << "What would you like the duration to be?" << std::endl;
        std::cin >> sDuration;
        duration = stoi(sDuration);
        newRandom(playlistName,duration);
    } else if (command == "quit"){
        quit();
    }
}

void UserInterface::help() {
    std::cout << "help: Summary of available commands." << std::endl;
    std::cout << "library: Display of all songs in library." << std::endl;
    std::cout << "artist songs: Display all songs by given artist." << std::endl;
    std::cout << "song info: Display all information about a given song." << std::endl;
    std::cout << "import: Import file of songs, to be added to library." << std::endl;
    std::cout << "discontinue: Remove all songs from library and playlists found on file." << std::endl;
    std::cout << "playlists: Display all playlists and their durations." << std::endl;
    std::cout << "playlist songs: Display all songs left and the duration of a given playlist." << std::endl;
    std::cout << "new playlist: Create a new empty playlist." << std::endl;
    std::cout << "add song: Add a song to a playlist." << std::endl;
    std::cout << "remove song: Remove a song from a playlist." << std::endl;
    std::cout << "play next: Display info on next song in a playlist." << std::endl;
    std::cout << "new random: Create a new playlist that populates with random songs from library." << std::endl;
    std::cout << "quit: Save the library/playlists and terminate program." << std::endl;
}

void UserInterface::library() {
    Library* lib;
    lib->printCollection();
}

void UserInterface::artistSongs(std::string artist) {
    Library* lib;
    lib->getArtist(artist);
}

void UserInterface::songInfo(std::string artist, std::string songTitle) {
    Library* lib;
    lib->getSong(songTitle);
}

void UserInterface::import(std::string filename) {
    //TODO
}

void UserInterface::discontinue(std::string filename) {
    //TODO
}

void UserInterface::allPlaylists() {
    PlaylistCollection* pl;
    pl->printCollection();
}

void UserInterface::playlistInfo(std::string playlistName) {
    //TODO
    Playlist* pl; //pin-point right playlist
    std::string str = pl->printCollection();
    std::cout << str << std::endl;
}

void UserInterface::newPlaylist(std::string playlistName) {
    //TODO
}

void UserInterface::addSong(std::string songName, std::string artistName, int duration, std::string playlistName) {
    //TODO
}

void UserInterface::removeSong(std::string songName, std::string artistName, std::string playlistName) {
    //TODO
}

void UserInterface::playNext(std::string playlistName) {
    //todo
}

void UserInterface::newRandom(std::string playlistName, int duration) {
    //todo
}

void UserInterface::quit() {
    //TODO
}