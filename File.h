//
// Created by aero1 on 12/10/2019.
//

#ifndef TEST_FILE_H
#define TEST_FILE_H

#include <string>
#include <iostream>
#include <fstream>

std::string toString(std::string* arrayPtr, int size);

std::string* toList(std::string str, int size);

int countChar(std::string stringToSearch, char characterToCount);

void load_library(std::string filename);


#endif //TEST_FILE_H
