//
// Created by Damel Albertos on 12/4/19.
//

#ifndef TERM_PROJECT_USERINTERFACE_H
#define TERM_PROJECT_USERINTERFACE_H
#include<string>
#include "Library.h"
#include "PlaylistCollection.h"
#include "Playlist.h"

class UserInterface {

public:
    //constructor
    UserInterface();

    /**
     * Reacts to command by user. Goes into another function
     * LOGIC:
     * if <command> call <function>
     */
    void reactToCommand(std::string command, Library libIn, PlaylistCollection plIn);

    /**
     * Prints out all the commands available to the user
     *LOGIC:
     * for loop iterating through the list of commands, printing 1 by 1
     * OR
     * 1 large string
    */
    void help();

    /**
     * Print all songs in alphabetical order by artist, alphabetical by song too
     * LOGIC:
     * call the printLibrary function from Library Class
     */
    void library(Library lib);

    /**
     * Print all songs by the artist
     * Parameters: artist
     * LOGIC:
     * call the getArtist function from the Library Class
     * Alphabetical?
     */
    void artistSongs(std::string artist, Library libIn);

    /**
     * Print info about a song
     * Parameters: artist, songTitle
     * LOGIC:
     * call the getSong function from the Library Class
     */
    void songInfo(std::string artist, std::string songTitle, Library lib);

    /**
     * Add all songs in the file to the library, print any duplicates
     * Parameters: filename
     * LOGIC:
     * call add function from Library class in a loop, going through file
     * HOW TO KEEP TRACK OF DUPLICATES???
     */
    static void import(std::string filename, Library lib);

    /**
     * Remove all songs on the file from the library and any playlists its on
     * (if we use a reference this should be done automatically)
     * Print any songs that couldn't be removed
     * Parameters: filename
     * LOGIC:
     * call the remove function from Library Class in a loop going through file
     */
    void discontinue(std::string filename, Library lib, PlaylistCollection pl);

    /**
     * Print out the names of all playlists and their duration times
     * Parameters: None
     * LOGIC:
     * call printCollection from PlaylistCollection Class
     */
    void allPlaylists(PlaylistCollection pl);

    /**
     * prints all songs in a playlist and their duration
     * Parameters: playlistName
     * LOGIC:
     * call printCollection from Playlist Class
     */
    void playlistInfo(std::string playlistName, PlaylistCollection pl);

    /**
     * create a new empty playlist with the given name
     * Parameters: playlistName
     * LOGIC:
     * create a new Playlist object (empty no songs, duration=0, songCount=0)
     * call add from PlaylistCollection Class
     */
    void newPlaylist(std::string playlistName, PlaylistCollection pl);

    /**
     * Add the given song to the library and to the given playlist
     * Parameters: songName, artistName, duration, playlistName
     * LOGIC:
     * create a new song object with the given parameters
     * call add function from Playlist Class
     */
    void addSong(std::string songName, std::string artistName, int duration, std::string playlistName, PlaylistCollection pl, Library lib);

    /**
     * remove the song from the given playlist
     * Parameters: songName, artistName, playlistName
     * LOGIC:
     * iterate through playlist to find song, call remove from Playlist Class on song
     */
    void removeSong(std::string songName, std::string artistName, std::string playlistName, PlaylistCollection pl);

    /**
     * print all info on next song in playlist, remove from playlist,
     * add to playcount, if playlist is empty, remove playlist from PlaylistCollection
     * Parameters: playlistName
     * LOGIC:
     * iterate through playlist, call getsonginfo,
     * remove function from PlaylistCollection Class
     */
    void playNext(std::string playlistName, PlaylistCollection pl);

    /**
     * generate a new playlist with the given name and populate it with random songs
     * no duplicates, shuffled, can't go over given duration
     * Parameters: playlistName, duration
     * LOGIC:
     * create a new playlist object with given name and duration, call add function from
     * PlaylistCollection Class
     */
    void newRandom(std::string playlistName, int duration, PlaylistCollection pl, Library lib);

    /**
     * save the library and all playlists, terminate execution
     * Parameters: None
     * LOGIC:
     * call saveCollection function from Library Class, call
     * saveCollection function from PlaylistCollection Class
     */
    void quit(std::string filename, PlaylistCollection pl, Library lib);

};

#endif //TERM_PROJECT_USERINTERFACE_H
