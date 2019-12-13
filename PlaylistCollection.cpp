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

void PlaylistCollection::genRandPlaylist(std::string name, float duration, Library songLib) {

    Playlist newRandPlaylist = Playlist(name);
    Song newSongToAdd;

    int randNumber;
    //library currSongCount
    int range = songLib.getCurrSongCount();
    range = range + 1;

    while(newRandPlaylist.getDuration()<= duration) {
        randNumber = rand()% range + 0;
        newSongToAdd = songLib.getCollection()->getValueAt(randNumber);
        if(newRandPlaylist.getSongCount() == 0) {
            newRandPlaylist.add(newSongToAdd);
        }
        else {
            for (int i = 0; i <= newRandPlaylist.getSongCount(); i++){
                if(newRandPlaylist.getPlaylist()->getValueAt(i)->getArtist() == newSongToAdd.getArtist() && newRandPlaylist.getPlaylist()->getValueAt(i)->getTitle() == newSongToAdd.getTitle()) {
                    randNumber = rand()% range + 0;
                }
            }
            newRandPlaylist.add(newSongToAdd);

        }
    }
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
    Playlist playlistToLookAt;
    for (int i = 0; i <= playlistArray->itemCount(); i++) {
        playlistToLookAt = playlistArray->getValueAt(i);
        for (int j = 0; j <= playlistToLookAt.getSongCount(); j++) {
            playlistToLookAt.remove(artist, name);
        }
    }
}

//todo Matt
void PlaylistCollection::saveCollection(std::string filename){
    std::ofstream outf(filename);
    if (outf){
<<<<<<< HEAD
        for (int i = 0; i < playlistArray->itemCount(); i++){
            Playlist currentPlaylist = playlistArray->getValueAt(i);
            currentPlaylist.saveCollection();
            outf << currentPlaylist.getName() << "\t" << currentPlaylist.getDuration() << currentPlaylist.getSongCount() << "\n";
        }
        outf.close();
=======
        //for loop through playlist collection
        //for (int i = 0; i <= placeholder; i++){
            //get current playlist
            //call Playlist::saveCollection() on the playlist
            //outf << playlist name << "\t" << playlist duration << playlist songCount << "\n";
>>>>>>> 65675b82ea345bdf0276260b78e011c5287f9d3b
    }
    outf.close();
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
