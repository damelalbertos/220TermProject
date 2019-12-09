//
// Created by Matt on 11/26/2019.
//

#ifndef PROJECT_PLAYLIST_H
#define PROJECT_PLAYLIST_H

class Playlist : Public MusicCollection{

private:
    std::string playlistName;
    LinkedQueue<Song>* songList;
    float duration;
    int songCount;

public:

    //constructor
    Playlist(std::string playlistName);

    //destructor
    ~Playlist();

    //copy constructor
    Playlist(const Playlist& playlistToCopy);

    //assignment operator
    Playlist& operator=(const Playlist& playlistToCopy);

    /**
    * gets the name of the playlist
    * @returns playlistName
    */
    std::string getPlaylistName();

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
    * gets the number of times a playlist has been played
    * @returns playlistPlaycount
    */
    int getPlayCount();

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
    void played();

    /**
    * removes a song from the beginning of the playlist queue
    * @param itemToRemove - the song you want to remove
    * @post sends an error if the user does not input a proper song object, deletes playlist if the song count is equal to zero
    */
    void remove(Song songToRemove);

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
    * @post sends error if the txt has incorrect data but still uplaod what is possible
    */
    void loadCollection();

};

#endif //PROJECT_PLAYLIST_H
