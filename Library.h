//
// Created by Matt on 11/26/2019.
//

#ifndef PROJECT_LIBRARY_H
#define PROJECT_LIBRARY_H

class Library : public MusicCollection{

private:
    Array* allSongs

public:

    Library(Array* songs);

    ~Library();

    Library(const Library& songCollectionToCopy);

    Library& operator=(const Library& songCollectionToCopy);

    void add(Song itemToAdd);

    void remove(Song itemToAdd);

    std::string printCollection();

    std::string getSong();

    std::string getArtist();

    void saveCollection();

    void loadCollection();


};

#endif //PROJECT_LIBRARY_H
