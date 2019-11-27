//
// Created by Matt on 11/26/2019.
//

#ifndef PROJECT_PLAYLISTLIBRARY_H
#define PROJECT_PLAYLISTLIBRARY_H


class PlaylistCollection : public MusicCollection{

private:
    Array* allPlaylists

public:

    PlaylistCollection(Array* playlists);

    ~PlaylistCollection();

    PlaylistCollection(const PlaylistCollection& playlistCollectionToCopy);

    PlaylistCollection& operator=(const PlaylistCollection& playlistCollectionToCopy);

    void add(Playlist itemToAdd);

    void remove(Playlist itemToAdd);

    std::string printCollection();

    void saveCollection();

    void loadCollection();


};

#endif //PROJECT_PLAYLISTLIBRARY_H
