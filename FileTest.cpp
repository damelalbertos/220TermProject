//
// Created by aero1 on 12/10/2019.
//

#include "File.h"
#include "TestLib.h"
#include "Library.h"


void countCharTest(){
    std::string testString = "Hello world";
    int testCount = countChar(testString, 'l');
    printAssertEquals(3,testCount);

    std::string testString2 = "H,e,l,l?o w!,#rld";
    int testCount2 = countChar(testString2, ',');
    printAssertEquals(4,testCount2);

    std::string testString3 = "H,e,l,l?o\n w!,#rld\n";
    int testCount3 = countChar(testString3, '\n');
    printAssertEquals(2,testCount3);

}

void toStringTest(){
    std::string testList[5]{"Hello","World","How","Are","You"};
    std::string listString = toString(testList,5);
    printAssertEquals("{Hello, World, How, Are, You}", listString);

    std::string testList2[4]{"Hello","How","Are","You"};
    std::string listString2 = toString(testList2,4);
    printAssertEquals("{Hello, How, Are, You}", listString2);

    std::string testList3[0]{};
    std::string listString3 = toString(testList3,0);
    printAssertEquals("{}", listString3);

}

void toListTest(){
    std::string testString = "Hello\tWorld\tHow\tAre\tYou";
    std::string* testList = toList(testString,countChar(testString,'\t')+1);
    printAssertEquals("{Hello, World, How, Are, You}", toString(testList,countChar(testString,'\t')+1));

    std::string testString2 = "How\tAre\tYou";
    std::string* testList2 = toList(testString2,countChar(testString2,'\t')+1);
    printAssertEquals("{How, Are, You}", toString(testList2,countChar(testString2,'\t')+1));

}

//todo
void loadLibraryTest(){
    Library testLib;
    testLib.loadCollection("testSmall.txt")
    testLib.printCollection();
}


int main(){
    countCharTest();
    toStringTest();
    toListTest();
    loadLibraryTest();
    return 0;
}