//
// Created by Matt on 11/26/2019.
//

#ifndef PROJECT_MUSICCOLLECTION_H
#define PROJECT_MUSICCOLLECTION_H

template class<T>
class MusicCollection{

private:
    MusicCollection(const MusicCollection& musicCollectionToCopy);
    MusicCollection& operator=(const MusicCollection& musicCollectionToCopy);

public:

    MusicCollection()

    ~MusicCollection();

    virtual void add(T itemToAdd)=0;

    virtual void remove(T itemToAdd)=0;

    virtual std::string printCollection()=0;

    virtual void saveCollection()=0;

    virtual void loadCollection()=0;


};

#endif //PROJECT_MUSICCOLLECTION_H
