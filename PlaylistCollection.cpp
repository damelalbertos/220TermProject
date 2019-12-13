//
// Created by Matt on 11/26/2019.
//
#include <iostream>
#include "PlaylistCollection.h"

//default constructor
PlaylistCollection::PlaylistCollection(){
    playlistArray = new ArrayList<Playlist>(10);
}

//todo
PlaylistCollection::PlaylistCollection(const PlaylistCollection& playlistCollectionToCopy){
}



void PlaylistCollection::add(Playlist playlistToAdd){
    playlistArray->insertAtEnd(playlistToAdd);
}

void PlaylistCollection::remove(std::string itemToRemove){
    Playlist playlistToLookAt;
    for(int i=0; i <= playlistArray->itemCount(); i++) {
        playlistToLookAt = playlistArray->getValueAt(i);
        if (playlistToLookAt.getName() == itemToRemove) {
            for (int i = 0; i <= playlistToLookAt.getSongCount(); i++) {
                playlistToLookAt.played();
            }
            playlistArray->removeValueAt(i);
        }
    }
}

void PlaylistCollection::printCollection(){
    std::string playlistAsString;

    for(int i=0; i <= playlistArray->itemCount(); i++) {
        Playlist playlistToLookAt = playlistArray->getValueAt(i);
        playlistAsString += playlistToLookAt.getName();
        playlistAsString += " : ";
        playlistAsString += playlistToLookAt.getDuration();
        playlistAsString += " Minutes";
        std::cout << playlistAsString << std::endl;
        playlistAsString = "";
    }

}



void PlaylistCollection::printAPlaylist(std::string playlistName){
    std::string playlistAsString;

    for(int i=0; i <= playlistArray->itemCount(); i++) {
        Playlist playlistToLookAt = playlistArray->getValueAt(i);
        if(playlistToLookAt.getName() == playlistName){
            playlistToLookAt.printCollection();
        }
        else{
            std::cout << "Playlist Not Found" << std::endl;
        }
    }

}

//todo
void PlaylistCollection::saveCollection(){

}

//todo
void PlaylistCollection::loadToCollection(){

}
