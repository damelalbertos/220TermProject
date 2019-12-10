//
// Created by Matt on 11/26/2019.
//

#ifndef PROJECT_PLAYLISTLIBRARY_H
#define PROJECT_PLAYLISTLIBRARY_H

#include "Playlist.h"
#include "ArrayList.h"


class PlaylistCollection : public MusicCollection{

private:

    ArrayList<Playlist>* playlistArray;
    int currPlaylistCount;
    int currCapacity;


public:
    //constructor
    PlaylistCollection(Playlist* playlists);

    //destructor
    ~PlaylistCollection();

    //copy constructor
    PlaylistCollection(const PlaylistCollection& playlistCollectionToCopy);

    //assignment operator
    PlaylistCollection& operator=(const PlaylistCollection& playlistCollectionToCopy);

    /**
    * adds a playlist to the end of the list of playlists
    * @param itemToAdd - the playlist you want to add
    * @post sends an error if the user does not input a proper playlist object
    */
    void add(Playlist itemToAdd);

    /**
    * removes a playlist from the list of playlists and shifts the rest down if necessary
    * @param itemToRemove - the playlist you want to remove
    * @post sends an error if the user does not input a proper playlist name or the playlist is not present
    */
    void remove(Playlist itemToRemove);

    /**
    * prints the names of all the playlists and their durations
    * @returns a string of all the playlists in the collection
    * @post sends an error if the list is empty
    */
    std::string printCollection();

    /**
    * saves the names, the duration and all songs incldued in an indidvidual playlist to a txt file
    * @post sends an error if the list is empty
    */
    void saveCollection();

    /**
    * loads the saved txt file of all the playlists and can be used to add new playlists
    * @post sends an error if the txt file is empty
    */
    void loadToCollection();


};

#endif //PROJECT_PLAYLISTLIBRARY_H
