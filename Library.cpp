//
// Created by Matt on 11/26/2019.
//
#include "Library.h"

Library(Array* songs);

~SongCollection();

SongCollection(const Library& songCollectionToCopy);

Library& operator=(const Library& songCollectionToCopy);

void add(Song itemToAdd);

void remove(Song itemToAdd);

std::string printCollection();

std::string getSong();

std::string getArtist();

void saveCollection();

void loadCollection();