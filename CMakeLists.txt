cmake_minimum_required(VERSION 3.12)
project(Term_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Term_Project Library.cpp Playlist.cpp PlaylistCollection.cpp Song.cpp ArrayLib.cpp ArrayList.inl File.cpp SongAndPlaylistTests.cpp)