//
// Created by Matt on 10/3/2019.
//

#include <string>
#include <stdexcept>
#include <iostream>

int genRandInt(int min, int max, int& numLinesRun){
    //parameters
    numLinesRun += 3;

    int temp;
    //temp and if
    numLinesRun += 2;

    if(min > max) {
        temp = min;
        min = max;
        max = temp;
        //inside if
        numLinesRun += 3;
    }

    int range = max - min;
    range = range + 1;
    temp = rand()% range + min;

    //return
    numLinesRun += 4;
    return temp;
}

int* genRandArray(int size, int min, int max, int& numLinesRun){
    //parameters
    numLinesRun += 4;

    //if
    numLinesRun += 1;
    if(size < 1){
        //inside if
        numLinesRun += 1;
        return nullptr;
    }

    int *randNumArray = new int[size];
    //array and for loop parameters
    numLinesRun += 4;

    for(int i = 0; i < size; i++){
        randNumArray[i] = genRandInt(min,max,numLinesRun);
        //inside for
        numLinesRun += 1;
    }

    //return
    numLinesRun += 1;
    return randNumArray;
}

std::string toString(const int* arrayPtr, int size){
    //parameters
    //numLinesRun += 3;

    std::string arrayAsString;
    //string and if
    //numLinesRun += 2;

    if (size >= 1){
        arrayAsString += "{";
        //inside if and for loop parameters
        //numLinesRun += 4;

        for (int i = 0; i < size; i++){
            arrayAsString += std::to_string(arrayPtr[i]);
            //inside for and if
            //numLinesRun+= 2;

            if (i < size - 1){
                arrayAsString += ", ";
                //inside if
                //numLinesRun += 1;
            }
        }
        arrayAsString += "}";

        //return
        //numLinesRun += 2;
        return arrayAsString;
    }
    else{
        arrayAsString = "{}";

        //return
        //numLinesRun += 2;
        return arrayAsString;
    }
}

int find(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    int foundNumIndex = -1;
    //parameters and declaration
    numLinesRun += 5;

    //for loop
    numLinesRun += 3;
    for (int i = 0; i < size; i++) {
        // inside for loop
        numLinesRun += 1;
        if (arrayPtr[i] == numToFind) {
            foundNumIndex = i;

            //inside if
            numLinesRun += 2;
            return foundNumIndex;
        }
    }

    //return
    numLinesRun += 1;
    return foundNumIndex;
}

int findLast(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    int foundNumIndex = -1;
    //parameters and declaration
    numLinesRun += 5;

    //for loop
    numLinesRun += 3;
    for (int i = 0; i < size; i++){
        //inside for loop
        numLinesRun += 1;
        if (arrayPtr[i] == numToFind){
            foundNumIndex = i;
            numLinesRun += 1;
        }
    }

    //return
    numLinesRun += 1;
    return foundNumIndex;
}

int findMaxIndex(const int* arrayPtr, int size, int& numLinesRun){
    int maxValue;
    int maxValueIndex = 0;
    //parameters and declaration
    numLinesRun += 5;

    //if
    numLinesRun += 1;
    if (size < 1){
        //inside if
        numLinesRun += 1;
        throw std::invalid_argument("size is less than 1");
    }

    else{
        //else
        numLinesRun += 1;

        maxValue = arrayPtr[0];
        //for loop
        numLinesRun += 4;
        for (int i = 0; i < size; i++){
            //inside for loop
            numLinesRun += 1;
            if (arrayPtr[i] > maxValue){
                maxValue = arrayPtr[i];
                //inside if
                numLinesRun += 1;
            }
        }

        //for loop
        numLinesRun += 3;
        for (int i = 0; i < size; i++){
            //inside for
            numLinesRun += 1;
            if (arrayPtr[i] == maxValue){
                maxValueIndex = i;
                //inside if and return
                numLinesRun += 2;
                return maxValueIndex;
            }
        }
    }
}

int* copyArray(const int* arrayToCopy, int size, int& numLinesRun){
    //parameters and if
    numLinesRun += 3;

    if (size < 1){
        //inside if
        numLinesRun += 1;
        return nullptr;
    }

    else{
        //else
        numLinesRun += 1;

        int *arrayCopy = new int[size];
        //for loop
        numLinesRun += 3;

        for (int i = 0; i < size; i++) {
            //inside for loop
            numLinesRun += 1;
            arrayCopy[i] = arrayToCopy[i];
        }
        //return
        numLinesRun += 1;
        return arrayCopy;
    }
}

int* genShuffledArray(int size, int& numLinesRun){
    //parameters and if
    numLinesRun += 3;

    if (size < 1){
        //inside if
        numLinesRun += 1;
        return nullptr;
    }

    else{
        //else
        numLinesRun += 1;

        int* shuffledArray = new int[size];
        int randIndex;
        int temp;

        //for loop
        numLinesRun += 6;

        for (int i = 0; i < size; i++){
            //inside if
            numLinesRun += 1;
            shuffledArray[i] = i + 1;
        }

        //for loop
        numLinesRun += 3;
        for (int i = 0; i < size; i++){
            randIndex = genRandInt(1,size-1,numLinesRun);
            temp = shuffledArray[i];
            shuffledArray[i] = shuffledArray[randIndex];
            shuffledArray[randIndex] = temp;
            //inside for loop
            numLinesRun += 4;
        }

        //return
        numLinesRun += 1;
        return shuffledArray;
    }
}

int countOccurrences(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    (numLinesRun) +=4;//parameters
    int occurrenceCount = 0;
    (numLinesRun) += 1;//variable
    (numLinesRun) += 2;//for loop
    for (int i = 0; i < size; i++){
        (numLinesRun) += 3;//for loop iterations
        if (arrayPtr[i] == numToFind){
            (numLinesRun) += 1;//if statement
            occurrenceCount++;
        }
    }
    (numLinesRun) += 1;//return
    return occurrenceCount;
}

void sort(int* arrayToSort, int size, int& numLinesRun){
    (numLinesRun) += 3;//Parameters
    int temp;
    (numLinesRun) += 1;//Variable
    (numLinesRun) += 4;//For loops
    for (int i = 0; i < (size -1); i++){
        for (int j = (i+1); j < size; j++){
            if (arrayToSort[i] > arrayToSort[j]){
                (numLinesRun) += 7;//each iteration of loops
                temp = arrayToSort[i];
                arrayToSort[i] = arrayToSort[j];
                arrayToSort[j] = temp;
            }
        }
    }
}

int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun){
    numLinesRun +=4; //parameters
    int left = 0;
    int right = size-1;
    int mid;
    numLinesRun +=3;//variables

    numLinesRun +=1;//while
    while(left <= right) {
        mid = (right + left)/2;
        if (arrayPtr[mid] > numToFind) {
            numLinesRun+=1;
            right = mid - 1;
        }
        else if (arrayPtr[mid] < numToFind) {
            numLinesRun+=1;
            left = mid + 1;
        }
        else{
            numLinesRun+=1;//return
            return mid;
        }
        numLinesRun+=2;//each interation
    }
    numLinesRun+=1;//return
    return -1;
}

int* merge(const int*a1, int size1, const int* a2, int size2, int& numLinesRun){
    numLinesRun +=5; //parameters

    numLinesRun +=1; //if
    if(size1 + size2 < 1){
        numLinesRun +=1; //return
        return nullptr;
    }
    else{

        int *newArray = new int[size1+size2];
        int i = 0;
        int j = 0;
        int k = 0;
        numLinesRun +=4; //variables

        numLinesRun +=1; //while
        while(size1 != 0 && size2 != 0) {

            if (a1[i] < a2[j]) {
                newArray[k] = a1[i];
                i++;
                k++;
                size1--;
                numLinesRun +=4;
            }
            else{
                newArray[k] = a2[j];
                j++;
                k++;
                size2--;
                numLinesRun +=4;
            }
            numLinesRun +=1; //interation
        }

        numLinesRun +=1; //while
        while(size1 > 0){
            newArray[k] = a1[i];
            i++;
            k++;
            size1--;
            numLinesRun +=4;
        }

        numLinesRun +=1; //while
        while(size2 > 0){
            newArray[k] = a2[j];
            j++;
            k++;
            size2--;
            numLinesRun +=4;
        }
        numLinesRun +=1;
        return newArray;
    }
}

int* mergeSort(const int* arrayToSort, int size, int& numLinesRun) {
    numLinesRun +=3; //parameters
    numLinesRun +=1; //if
    if (size < 1) {
        numLinesRun +=1;
        return nullptr;
    }
    else{
        int mid = (0+size)/2;
        int a1Size = mid;
        int a2Size = size - mid;
        int a1[a1Size];
        int a2[a2Size];
        numLinesRun +=5;

        numLinesRun +=2;
        for(int i = 0; i < size; i++){
            if(i < mid){
                numLinesRun +=1;
                a1[i] = arrayToSort[i];
            }
            else{
                numLinesRun +=1;
                a2[i - mid] = arrayToSort[i];
            }
            numLinesRun +=1;
        }
        sort(a1, a1Size, numLinesRun);
        sort(a2, a2Size, numLinesRun);
        numLinesRun +=3;
        return merge(a1, a1Size, a2, a2Size, numLinesRun);
    }
}