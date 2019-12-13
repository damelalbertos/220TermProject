//
// Created by Matt on 12/8/2019.
//

#include "TestLib.h"
#include "Song.h"
#include "Library.h"

void addTests(){
    Song mySong1 =  Song("King Gizzard and the Lizard Wizard", "The spider and me", 193.2);
    Song mySong2 =  Song("Led Zeppelin", "Stairway to Heaven", 481.8);
    Song mySong3 =  Song("Lorde", "The Love Club", 202.2);


    Library testLib = Library();
    testLib.add(mySong1);
    testLib.add(mySong2);
    testLib.add(mySong3);



}

void removeTests(){
    Song mySong1 =  Song("King Gizzard and the Lizard Wizard", "The spider and me", 193.2);
    Song mySong2 =  Song("Led Zeppelin", "Stairway to Heaven", 481.8);
    Song mySong3 =  Song("Lorde", "The Love Club", 202.2);
    Song mySong4 =  Song("The Knocks", "No Requests", 190.8);
    Song mySong5 =  Song("ASAP Ferg", "Work", 166.8);

    Library testLib = Library();
    testLib.add(mySong1);
    testLib.add(mySong2);
    testLib.add(mySong3);
    testLib.add(mySong4);
    testLib.add(mySong5);

    testLib.printCollection();

    testLib.remove(mySong3);
    testLib.remove(mySong2);

    std::cout << "Should be:\n"
              << "Artist:\tTitle:\tDuration (seconds):\tPlay Count:\n"
              << "King Gizzard and the Lizard Wizard\tThe spider and me\t193.2\t0\n"
              << "The Knocks\tNo Requests\t190.8\t0\n"
              << "ASAP Ferg\tWork\t166.8\t0" << std::endl;
    testLib.printCollection();


}



//int main(){
//
//    addTests();
//
//    return 0;
//}