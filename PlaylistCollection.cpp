//
// Created by Matt on 11/26/2019.
//
#include <iostream>
#include "PlaylistCollection.h"

//default constructor
PlaylistCollection::PlaylistCollection(){
    playlistArray = new ArrayList<Playlist>(10);
}

PlaylistCollection::PlaylistCollection(const PlaylistCollection& playlistCollectionToCopy){
    //todo
}

PlaylistCollection::~PlaylistCollection() {
    delete playlistArray;
}

void PlaylistCollection::genRandPlaylist(std::string name, float duration, Library songLib) {

    Playlist newRandPlaylist = Playlist(name);
    Song newSongToAdd;
    std::string songTitle;
    std::string songArtist;

    int randNumber;
    //library currSongCount
    int range = songLib.getCurrSongCount();
    range = range + 1;

    while(newRandPlaylist.getDuration()<= duration) {
        randNumber = rand()% range + 0;
        newSongToAdd = songLib.getCollection()->getValueAt(randNumber);
        songArtist = newSongToAdd.getArtist();
        songTitle = newSongToAdd.getTitle();

        if(newRandPlaylist.getSongCount() == 0) {
            newRandPlaylist.add(newSongToAdd);
        }
        else {
            for (int i = 0; i <= newRandPlaylist.getSongCount(); i++){
                if(newRandPlaylist.findSong(songArtist, songTitle)->getArtist() == newSongToAdd.getArtist() && newRandPlaylist.findSong(songArtist, songTitle)->getTitle() == newSongToAdd.getTitle()) {
                    randNumber = rand()% range + 0;
                }
            }
            newRandPlaylist.add(newSongToAdd);

        }
    }
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

    for(int i=0; i <= playlistArray->itemCount(); i++) {
        Playlist playlistToLookAt = playlistArray->getValueAt(i);
        if(playlistToLookAt.getName() == playlistName){
            playlistToLookAt.printCollection();
        }
    }

    std::cout << "Playlist Not Found" << std::endl;

}

Playlist PlaylistCollection::getPlaylist(std::string playlistName){
    for(int i=0; i <= playlistArray->itemCount(); i++) {
        Playlist playlistToLookAt = playlistArray->getValueAt(i);
        if(playlistToLookAt.getName() == playlistName){
            return playlistToLookAt;
        }
    }

    std::cout << "Playlist Not Found" << std::endl;
}

void PlaylistCollection::removeFromAll(Song songToRemove) {
    std::string artist = songToRemove.getArtist();
    std::string name = songToRemove.getTitle();
    Playlist playlistToLookAt;
    for (int i = 0; i <= playlistArray->itemCount(); i++) {
        playlistToLookAt = playlistArray->getValueAt(i);
        for (int j = 0; j <= playlistToLookAt.getSongCount(); j++) {
            playlistToLookAt.remove(artist, name);
        }
    }
}

void PlaylistCollection::saveCollection(std::string filename){
    std::ofstream outf(filename);
    if (outf){
        for (int i = 0; i < playlistArray->itemCount(); i++){
            Playlist currentPlaylist = playlistArray->getValueAt(i);
            currentPlaylist.saveCollection();
            outf << currentPlaylist.getName() << "\t" << currentPlaylist.getDuration() << currentPlaylist.getSongCount() << "\n";
        }
        outf.close();
    }
}


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
                Playlist newPlaylist = Playlist(name);
                std::string playlistFile = newPlaylist.getName() + ".txt";
                newPlaylist.loadCollection(playlistFile);
                add(newPlaylist);
            }
        }
    } else {
        std::cerr << "File not found." << std::endl;
    }


}

void PlaylistCollection::discontinuePlaylists(std::string filename) {
    for (int i = 0; i < playlistArray->itemCount(); i++){
        Playlist currentPlaylist = playlistArray->getValueAt(i);
        currentPlaylist.discontinue(filename);
    }
}
