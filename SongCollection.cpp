//
// Created by Matt on 11/26/2019.
//
#include "SongCollection.h"

SongCollection(Array* songs);

~SongCollection();

SongCollection(const SongCollection& songCollectionToCopy);

SongCollection& operator=(const SongCollection& songCollectionToCopy);

void add(Song itemToAdd);

void remove(Song itemToAdd);

std::string printCollection();

std::string getSong();

std::string getArtist();

void saveCollection();

void loadCollection();