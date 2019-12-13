//
// Created by Matt on 11/26/2019.
//

#ifndef PROJECT_PLAYLIST_H
#define PROJECT_PLAYLIST_H

#include "LinkedNode.h"
#include "Song.h"
#include "LinkedList.h"
#include "File.h"
#include <string>
#include <iostream>
#include "MusicCollection.h"


class Playlist {

private:
    std::string playlistName;
    LinkedList<Song*>* songsInPlaylist;
    float duration;
    int songCount;

public:
    Playlist();

    //constructor
    Playlist(std::string playlistName);

    //destructor
    ~Playlist();


    /**
    * gets the name of the playlist
    * @returns playlistName
    */
    std::string getName();

    /**
    * gets the duration of a playlist
    * @returns duration
    */
    float getDuration();

    /**
    * gets the number of songs in a playlist
    * @returns songCount
    */
    int getSongCount();

    /**
     * returns songsInPlaylist
     * @return songsInPlaylist
     *
     */
    LinkedList<Song*>* getPlaylist();

    /**
    * adds a song to the end of the playlist queue
    * @param itemToAdd - the song you want to add
    * @post sends an error if the user does not input a proper song object
    */
    void add(Song songToAdd);

    /**
    * removes a song from the beginning of the playlist queue
    * @post deletes a playlist if song count is equal to zero otherwise removes song after played
    */
    std::string played();

    void Playlist::discontinuePlaylist(std::string filename);

    /**
    * removes a song from anywhere in the playlist
    * @param itemToRemove - the song you want to remove
    * @post sends an error if the user does not input a proper song object, deletes playlist if the song count is equal to zero
    */
    void remove(std::string artistToRemove, std::string songToRemove);

    /**
    * prints the all the songs in the playlist with song with all information
    * @post sends error if list is empty
    */
    std::string printCollection();

    /**
    * saves the playlist to a txt file
    * @post sends error if list is empty
    */
    void saveCollection();

    /**
    * loads the playlist from a txt file
     * @param filename - name of file to import into playlist
    * @post sends error if the txt has incorrect data but still uplaod what is possible
    */
    void loadCollection(std::string filename);

};

#endif //PROJECT_PLAYLIST_H
