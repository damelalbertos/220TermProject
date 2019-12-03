//
// Created by Matt on 11/26/2019.
//
#include "PlaylistCollection.h"

PlaylistCollection::PlaylistCollection(Array* playlists){
    allPlaylists = playlists;
}

PlaylistCollection::~PlaylistCollection(){
    allPlaylists.clearList();
}

PlaylistCollection::PlaylistCollection(const PlaylistCollection& playlistCollectionToCopy);

PlaylistCollection::PlaylistCollection& operator=(const PlaylistCollection& playlistCollectionToCopy);

void PlaylistCollection::add(Playlist itemToAdd){
    allPlaylists.insertAtEnd(itemToAdd);
}

void PlaylistCollection::remove(Playlist itemToRemove){
    int indexToRemove = allPlaylists.find(itemToRemove);
    allPlaylists.remove(indexToRemove);
}

std::string PlaylistCollection::printCollection();

void PlaylistCollection::saveCollection();

void PlaylsitCollection::loadToCollection();
