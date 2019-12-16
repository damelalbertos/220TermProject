//
// Created by Matt on 11/26/2019.
//

#ifndef PROJECT_PLAYLISTLIBRARY_H
#define PROJECT_PLAYLISTLIBRARY_H

#include "Playlist.h"
#include "ArrayList.h"
#include "Library.h"



class PlaylistCollection {

private:

    ArrayList<Playlist>* playlistArray;


public:
    //constructor
    PlaylistCollection();

    //destructor
    ~PlaylistCollection();

    //copy constructor
    PlaylistCollection(const PlaylistCollection& playlistCollectionToCopy);

    /**
     * genereates a playlist of random songs based off the duration
     * @param name
     * @param duration
     */
    void genRandPlaylist(std::string name, float duration, Library songLib);

    /**
    * adds a playlist to the end of the list of playlists
    * @param itemToAdd - the playlist you want to add
    * @post sends an error if the user does not input a proper playlist object
    */
    void add(Playlist itemToAdd);

    Playlist getPlaylist(std::string playlistName);
    
    /**
    * removes a playlist from the list of playlists and shifts the rest down if necessary
    * @param itemToRemove - the playlist you want to remove
    * @post sends an error if the user does not input a proper playlist name or the playlist is not present
    */
    void remove(std::string itemToRemove);

    /**
     * removes a song from every playlist in a collection
     * @param songToRemove
     * @post the song will be removed from every playlist
     */
    void removeFromAll(Song songToRemove);

    /**
    * prints the names of all the playlists and their durations
    * @returns a string of all the playlists in the collection
    * @post sends an error if the list is empty
    */
    void printCollection();

    /**
    * prints the requested playlist and its durations
    * @returns a string of all the playlists in the collection
    * @post sends an error if the list is empty
    */
    void printAPlaylist(std::string playlistName);

    /**
    * saves the names, the duration and all songs incldued in an indidvidual playlist to a txt file
     * @param filename - name of the file to save to
    * @post sends an error if the list is empty
    */
    void saveCollection(std::string filename);

    /**
    * loads the saved txt file of all the playlists and can be used to add new playlists
     * @param filename - name of the file to save to
    * @post sends an error if the txt file is empty
    */
    void loadToCollection(std::string filename);

    void discontinuePlaylists(std::string filename);

};

#endif //PROJECT_PLAYLISTLIBRARY_H
