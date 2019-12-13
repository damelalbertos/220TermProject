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


    printAssertEquals(Song("King Gizzard and the Lizard Wizard", "The spider and me", 193.2), testLib.getCollection()->getValueAt(0));
    printAssertEquals(Song("Led Zeppelin", "Stairway to Heaven", 481.8), testLib.getCollection()->getValueAt(1));
    printAssertEquals(Song("Lorde", "The Love Club", 202.2), testLib.getCollection()->getValueAt(2));

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

    printAssertEquals(Song("King Gizzard and the Lizard Wizard", "The spider and me", 193.2), testLib.getCollection()->getValueAt(0));
    printAssertEquals(Song("The Knocks", "No Requests", 190.8), testLib.getCollection()->getValueAt(1));
    printAssertEquals(Song("ASAP Ferg", "Work", 166.8), testLib.getCollection()->getValueAt(2));


}

void getCurrSongCountTests(){
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
    printAssertEquals(5,testLib.getCurrSongCount());

    testLib.remove(mySong3);
    testLib.remove(mySong2);

    printAssertEquals(3,testLib.getCurrSongCount());

}

void getCurrCapacityTests(){
    Song mySong1 =  Song("King Gizzard and the Lizard Wizard", "The spider and me", 193.2);
    Song mySong2 =  Song("Led Zeppelin", "Stairway to Heaven", 481.8);
    Song mySong3 =  Song("Lorde", "The Love Club", 202.2);
    Song mySong4 =  Song("The Knocks", "No Requests", 190.8);
    Song mySong5 =  Song("ASAP Ferg", "Work", 166.8);
    Song mySong6 =  Song("Freddie Gibbs", "Cataracts", 148);
    Song mySong7 =  Song("Tom Waits", "Old '52", 200);
    Song mySong8 =  Song("New Order", "Age of Consent", 194.5);
    Song mySong9 =  Song("Kanye West", "Freestyle 4", 94.2);
    Song mySong10 =  Song("Bob Dylan", "Hurricane", 402.6);

    Library testLib = Library();
    testLib.add(mySong1);
    testLib.add(mySong2);
    testLib.add(mySong3);
    testLib.add(mySong4);
    testLib.add(mySong5);
    printAssertEquals(10,testLib.getCurrCapacity());
    testLib.add(mySong6);
    testLib.add(mySong7);
    testLib.add(mySong8);
    testLib.add(mySong9);
    printAssertEquals(10,testLib.getCurrCapacity());
    testLib.add(mySong10);
    printAssertEquals(20,testLib.getCurrCapacity());

}

void testPrintLibrary(){
    Song mySong1 =  Song("King Gizzard and the Lizard Wizard", "The spider and me", 193.2);
    Song mySong2 =  Song("Led Zeppelin", "Stairway to Heaven", 481.8);
    Song mySong3 =  Song("Lorde", "The Love Club", 202.2);
    Song mySong4 =  Song("The Knocks", "No Requests", 190.8);

    Library testLib = Library();
    testLib.add(mySong1);
    testLib.add(mySong2);
    testLib.add(mySong3);
    testLib.add(mySong4);

    std::cout << "Should be:\n"
            << "King Gizzard and the Lizard Wizard\tThe spider and me\t193.2\t0\n"
            << "Led Zeppelin\tStairway to Heaven\t481.8\t0\n"
            << "Lorde\tThe Love Club\t202.2\t0\n"
            << "The Knocks\tNo Requests\t190.8\t0" << std::endl;

    testLib.printCollection();
}

void testLoadLibrary(){
    Library testLib = Library();

    testLib.loadCollection("testSmall.txt");

    printAssertEquals(6,testLib.getCurrSongCount());

    std::cout << "Should be:\n"
              << "100 gecs\t745 sticky\t141.29\t0\n"
              << "100 gecs\tmoney machine\t114.46\t0\n"
              << "100 gecs\t800db cloud\t140.183\t0\n"
              << "2 Chainz\tForgiven (feat. Marsha Ambrosius)\t323.306\t0\n"
              << "2 Chainz\tThreat 2 Society\t225.8\t0\n"
              << "Aaron Copland\tDance Symphony: I. Dance of the Adolescent\t416.266\t0" << std::endl;

    testLib.printCollection();

}

void testDiscontinue(){
    Library testLib = Library();

    testLib.loadCollection("testSmall.txt");

    std::cout << "Should be:\n"
              << "100 gecs\t745 sticky\t141.29\t0\n"
              << "100 gecs\tmoney machine\t114.46\t0\n"
              << "100 gecs\t800db cloud\t140.183\t0\n"
              << "2 Chainz\tForgiven (feat. Marsha Ambrosius)\t323.306\t0\n"
              << "2 Chainz\tThreat 2 Society\t225.8\t0\n"
              << "Aaron Copland\tDance Symphony: I. Dance of the Adolescent\t416.266\t0" << std::endl;

    testLib.printCollection();

    PlaylistCollection unusedCollection;

    testLib.discontinue("testDiscontinue.txt", unusedCollection);

    std::cout << "Should be:\n"
              << "100 gecs\t745 sticky\t141.29\t0\n"
              << "100 gecs\tmoney machine\t114.46\t0\n"
              << "Aaron Copland\tDance Symphony: I. Dance of the Adolescent\t416.266\t0" << std::endl;

    testLib.printCollection();

    printAssertEquals(3,testLib.getCurrSongCount());
}

void getSongTests(){
    Library testLib = Library();
    testLib.loadCollection("testSmall.txt");

    printAssertEquals(Song("100 gecs", "745 sticky", 141.29), testLib.getSong("100 gecs", "745 sticky"));
    printAssertEquals(Song("100 gecs", "money machine", 114.46), testLib.getSong("100 gecs", "money machine"));
    printAssertEquals(Song("100 gecs", "800db cloud", 140.183), testLib.getSong("100 gecs", "800db cloud"));
    printAssertEquals(Song("2 Chainz", "Forgiven (feat. Marsha Ambrosius)", 323.306), testLib.getSong("2 Chainz", "Forgiven (feat. Marsha Ambrosius)"));
    printAssertEquals(Song("2 Chainz", "Threat 2 Society", 225.8), testLib.getSong("2 Chainz", "Threat 2 Society"));
    printAssertEquals(Song("Aaron Copland", "Dance Symphony: I. Dance of the Adolescent", 416.266), testLib.getSong("Aaron Copland", "Dance Symphony: I. Dance of the Adolescent"));

    std::cout << "Should raise error:" << std::endl;
    testLib.getSong("Led Zeppelin", "Kashmir");


}

void getArtistTests(){
    Library testLib = Library();
    testLib.loadCollection("testSmall.txt");

    std::cout << "Should be:\n"
              << "100 gecs\t745 sticky\t141.29\t0\n"
              << "100 gecs\tmoney machine\t114.46\t0\n"
              << "100 gecs\t800db cloud\t140.183\t0\n" << std::endl;
    testLib.getArtist("100 gecs");

    std::cout << "Should raise error:" << std::endl;
    testLib.getArtist("Led Zeppelin");

    std::cout << "Should be:\n"
              << "2 Chainz\tForgiven (feat. Marsha Ambrosius)\t323.306\t0\n"
              << "2 Chainz\tThreat 2 Society\t225.8\t0\n" << std::endl;
    testLib.getArtist("2 Chainz");

    std::cout << "Should raise error:" << std::endl;
    testLib.getArtist("King Crimson");


}

void saveCollectionTests(){
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

    testLib.saveCollection("saveLibTest.txt");

    testLib.remove(mySong1);
    testLib.remove(mySong2);
    testLib.remove(mySong3);
    testLib.remove(mySong4);
    testLib.remove(mySong5);

    testLib.loadCollection("saveLibTest.txt");

    printAssertEquals(Song("King Gizzard and the Lizard Wizard", "The spider and me", 193.2), testLib.getCollection()->getValueAt(0));
    printAssertEquals(Song("Led Zeppelin", "Stairway to Heaven", 481.8), testLib.getCollection()->getValueAt(1));
    printAssertEquals(Song("Lorde", "The Love Club", 202.2), testLib.getCollection()->getValueAt(2));
    printAssertEquals(Song("The Knocks", "No Requests", 190.8), testLib.getCollection()->getValueAt(3));
    printAssertEquals(Song("ASAP Ferg", "Work", 166.8), testLib.getCollection()->getValueAt(4));

}

int main(){
    addTests();
    getSongTests();
    getArtistTests();
    removeTests();
    getCurrSongCountTests();
    getCurrCapacityTests();
    testPrintLibrary();
    testLoadLibrary();
    testDiscontinue();
    saveCollectionTests();
    return 0;
}