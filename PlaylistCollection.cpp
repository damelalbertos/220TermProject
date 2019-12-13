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

void PlaylistCollection::genRandPlaylist(std::string name, float duration) {

}

Playlist PlaylistCollection::getPlaylist(std::string name) {
    int playlistToReturn = playlistArray->find(name);
    return playlistArray->getValueAt(playlistToReturn);
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
    }

    std::cout << "Playlist Not Found" << std::endl;

}

void PlaylistCollection::removeFromAll(Song songToRemove) {
    std::string artist = songToRemove.getArtist();
    std::string name = songToRemove.getTitle();
    //todo Matt: for loop through every playlist in the collection and call remove using the artist and name
}

//todo Matt
void PlaylistCollection::saveCollection(std::string filename){
    std::ofstream outf(filename);
    if (outf){
        //for loop through playlist collection
        //for (int i = 0; i <= placeholder; i++){
            //get current playlist
            //call Playlist::saveCollection() on the playlist
            //outf << playlist name << "\t" << playlist duration << playlist songCount << std::endl;
        }
        outf.close();
    }

}

//todo Matt
void PlaylistCollection::loadToCollection(std::string filename){
    std::ifstream infile(filename);
    if (infile) {
        while (infile) {
            std::string strInput;
            getline(infile, strInput);
            if (strInput != "") {
                int size = countChar(strInput, '\t') + 1;
                std::string *playlist = toList(strInput, size);
                std::string name = playlist[0];
                float duration = std::stoi(playlist[1]);
                int songCount = std::stoi(playlist[2]);
                //create new playlist using name/duration/songCount, I think the structure of Playlist needs to be changed for this
                //add the playlist to the collection
            }
        }
    } else {
        std::cerr << "File not found." << std::endl;
    }


}
