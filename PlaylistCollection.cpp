//
// Created by Matt on 11/26/2019.
//
#include "PlaylistCollection.h"

//default constructor
PlaylistCollection::PlaylistCollection(){
    playlistArray = new ArrayList<Playlist>(10);
}

PlaylistCollection::PlaylistCollection(const PlaylistCollection& playlistCollectionToCopy){

}

PlaylistCollection::PlaylistCollection& operator=(const PlaylistCollection& playlistCollectionToCopy){

}

void PlaylistCollection::add(Playlist playlistToAdd){
    playlistArray->insertAtEnd(playlistToAdd);
}

//todo
void PlaylistCollection::remove(Playlist itemToRemove){

}

std::string PlaylistCollection::printCollection(){
    std::string playlistsAsString;

    if (currCapacity >= 1){
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

        return playlistsAsString;
    }
}

//todo
void PlaylistCollection::saveCollection(){

}

//todo
void PlaylistCollection::loadToCollection(){

}
