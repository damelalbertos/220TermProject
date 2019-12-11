//
// Created by aero1 on 12/10/2019.
//

#include "File.h"
#include "Song.h"
#include "Library.h"

int countChar(std::string stringToSearch, char characterToCount){
    int length = stringToSearch.length();
    int count = 0;
    for (int i = 0; i < length; i++){
        if (stringToSearch[i] == characterToCount){
            count++;
        }
    }
    return count;
}

std::string toString(std::string* arrayPtr, int size){
    std::string final = "{";
    if (size < 1){
        final = "{}";
    }
    else {
        for (int i = 0; i < size; i++) {
            final += arrayPtr[i];
            if ((size - i) != 1) {
                final += ", ";
            }
        }
        final += "}";
    }
    return final;

}

std::string* toList(std::string str, int size){
    std::string* strList = new std::string[size];
    std::string newString;
    int length = str.length();
    int index = 0;
    int i;
    for (i = 0; i < length; i++){
        if ((str[i] != '\t') and (str[i] != '\r') and (str[i] != '\n')){
            newString += str[i];
        }
        else{
            strList[index] = newString;
            newString = "";
            index++;
        }
    }
    return strList;
}


void load_library(std::string filename){
    std::ifstream infile(filename);
    if (infile) {
        while (infile) {
            std::string strInput;
            getline(infile, strInput);
            if (strInput != "") {
                int size = countChar(strInput, '\t') + 1;
                std::string* song = toList(strInput, size);
                std::string artist = song[0];
                std::string name = song[1];
                float duration = stoi(song[2]) / 1000;
                Song newSong = Song(artist, name, duration);
            }
        }
    }
    else {
        std::cerr << "File not found." << std::endl;
    }
}