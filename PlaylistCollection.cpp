//
// Created by Matt on 11/26/2019.
//
#include "PlaylistCollection.h"

//default constructor
PlaylistCollection::PlaylistCollection(){
    playlistArray = new Playlist [10];
    currCapacity = 10;
    currPlaylistCount = 0;
}

//constructor


PlaylistCollection::~PlaylistCollection(){

}

PlaylistCollection::PlaylistCollection(const PlaylistCollection& playlistCollectionToCopy);

PlaylistCollection::PlaylistCollection& operator=(const PlaylistCollection& playlistCollectionToCopy);

void PlaylistCollection::add(Playlist playlistToAdd){
    if(currCapacity == currPlaylistCount && currItemCount != 0){
        doubleCapacity(currCapacity, playlistArray);
        playlistArray[currItemCount+1]=playlistToAdd;
        currItemCount++;
    }
    else{
        array[currPlaylistCount+1]=playlistToAdd;
        currItemCount++;
    };
}

//todo
void PlaylistCollection::remove(Playlist itemToRemove){
    int indexToRemove = allPlaylists.find(itemToRemove);
    allPlaylists.remove(indexToRemove);
}

std::string PlaylistCollection::printCollection(){
    std::string playlistsAsString;

    if (size >= 1){
        for (int i = 0; i < currPlaylistCount; i++){
            playlistsAsString += std::to_string(playlistArray[i].getName);
            playlistsAsString += " : ";
            playlistsAsString += std::to_string(playlistArray[i].getDuration);
            playlistsAsString += " Minutes";
            playlistsAsString += "\n";
        }
        return playlistsAsString;
    }
    else{
        playlistsAsString = "No playlists made yet";

        return arrayAsString;
    }
}

//todo
void PlaylistCollection::saveCollection();

//todo
void PlaylsitCollection::loadToCollection();
