//
// Created by Matt on 11/26/2019.
//

#ifndef PROJECT_LIBRARY_H
#define PROJECT_LIBRARY_H

#include "Song.h"
#include "ArrayList.h"

class Library : public MusicCollection{

private:
    ArrayList<Song>* allSongs;
    int currSongCount;
    int currCapacity;

public:

    Library();

    ~Library();

    Library(const Library& songCollectionToCopy);

    Library& operator=(const Library& songCollectionToCopy);

    /**
    * adds a song to the end of the list of songs
    * @param itemToAdd - the song you want to add
    * @post sends an error if the user does not input a proper song object
    */
    void add(Song itemToAdd);

    /**
    * removes a song from the list of songs and shifts the rest down if necessary
    * @param itemToRemove - the song you want to remove
    * @post sends an error if the user does not input a proper song name or the song is not present
    */
    void remove(Song itemToRemove);

    /**
    * prints all the info of all the songs
    * @returns a string of all the songs in the collection
    * @post sends an error if the list is empty
    */
    std::string printCollection();

    /**
    * returns the info of a specific song
    * @returns a string of all the songs in the collection
    * @post sends an error if the list is empty
    */
    std::string getSong();

    /**
    * returns all of the songs of an artist
    * @returns a string of all the songs in the collection
    * @post sends an error if the list is empty
    */
    std::string getArtist();

    /**
    * saves the names, the duration and all songs to a txt file
    * @post sends an error if the list is empty
    */
    void saveCollection();

    /**
    * loads the saved txt file of all the songs and can be used to add new songs
    * @post sends an error if the txt file is empty
    */
    void loadCollection();


};

#endif //PROJECT_LIBRARY_H
