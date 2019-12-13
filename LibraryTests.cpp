//
// Created by Matt on 12/8/2019.
//

#include "TestLib.h"
#include "Song.h"
#include "Library.h"

void addAndGetSong(){
    Song* testSong = new Song("testArtist", "testTitle", 2);
    Library* lib;
    Song result = lib->getSong(testSong->getArtist(), testSong->getTitle());
    printAssertEquals(testSong->getTitle(), result.getTitle()); //string
}

int main(){
    addAndGetSong();

    return 0;
}