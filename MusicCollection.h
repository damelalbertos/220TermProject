//
// Created by Matt on 11/26/2019.
//

#ifndef PROJECT_MUSICCOLLECTION_H
#define PROJECT_MUSICCOLLECTION_H

#include"string"


template <class T>;
class MusicCollection{

private:

    MusicCollection(const MusicCollection& musicCollectionToCopy);
    MusicCollection& operator=(const MusicCollection& musicCollectionToCopy);

public:

    MusicCollection();

    ~MusicCollection();

    /**
    * adds an item to the collection
    * @param itemToAdd - the object you want to add
    * @post sends an error if the entry item is invalid
    */
    virtual void add(T itemToAdd)=0;

    /**
    * removes an item from the collection
    * @param itemToRemove- the object you want to remove
    * @post sends an error if the item to remove is invalid or if the collection is empty
    */
    virtual void remove(T itemToRemove)=0;

    /**
    * prints the collection
    * @post sends an error if the collection is empty
    */
    virtual std::string printCollection()=0;

    /**
    * saves collection to a txt file
    * @post sends an error if the collection is empty
    */
    virtual void saveCollection()=0;

    /**
    * loads collection from a txt file
    * @post sends an error if the data in the txt is invalid but still uploads what it can
    */
    virtual void loadCollection()=0;


};

#endif //PROJECT_MUSICCOLLECTION_H
