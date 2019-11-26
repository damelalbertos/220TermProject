//
// Created by Matt on 10/15/2019.
//
#include <iostream>
#include "ArrayList.h"
#include "../ArrayLib/ArrayLib.h"

ArrayList::ArrayList(int initialCapacity) {
    if (initialCapacity < 1) {
        throw std::invalid_argument("In ArrayList constructor, size must be > 0");
    }
    else {
        array = new int[initialCapacity];
        currItemCount = 0;
        currCapacity = initialCapacity;
    }
}

//Copy Constructor
ArrayList::ArrayList(const ArrayList& arrayListToCopy){
    for (int i = 0; i < currCapacity; i++) {
        this->array[i] = arrayListToCopy.array[i];
    }
    this->currItemCount = arrayListToCopy.currItemCount;
    this->currCapacity = arrayListToCopy.currCapacity;
}

//Overloaded Assignment Operator
ArrayList& ArrayList::operator=(const ArrayList& arrayListToCopy){
    if(this != &arrayListToCopy){
        delete[] this->array;
        this->array = nullptr;

        this->currItemCount = arrayListToCopy.currItemCount;
        this->currCapacity = arrayListToCopy.currCapacity;
        this->array = arrayListToCopy.array;
        for (int i = 0; i < arrayListToCopy.currCapacity; i++) {
            this->array[i] = arrayListToCopy.array[i];
        }
    }
}

//Destructor
ArrayList::~ArrayList(){
    array = nullptr;
}

void ArrayList::insertAtEnd(int itemToAdd){
    if(currCapacity == currItemCount && currItemCount != 0){
        doubleCapacity(currCapacity, array);
        array[currItemCount+1]=itemToAdd;
        currItemCount++;
    }
    else{
        array[currItemCount+1]=itemToAdd;
        currItemCount++;
    };

}

int ArrayList::getValueAt(int index){
    if (index < 0 || index > currItemCount) {
        throw std::out_of_range("Bad index given to getValueAt: "+ std::to_string(index));
    }
    else {
        return array[index +1];
    }
}

std::string ArrayList::toString(){
    return ::toString(array+1,currItemCount);
}

bool ArrayList::isEmpty(){
    bool empty;

    for(int i =0; i < currCapacity; i++){
        if(array[i] == NULL){
            empty = true;
        }
        else{
            empty = false;
        }
    }

    if(empty == true){
        return true;
    }
    else{
        return false;
    }
}

int ArrayList::itemCount(){
    return currItemCount;
}

void ArrayList::clearList(){
    for(int i =1; i < currCapacity; i++){
        array[i] = NULL;
    }
    currItemCount = 0;
}

int ArrayList::find(int numToFind){
    int foundNumIndex = -1;

    for (int i = 1; i < currItemCount+1; i++) {

        if (array[i] == numToFind) {
            foundNumIndex = i;
            return foundNumIndex-1;
        }
    }
    return foundNumIndex;
}

int ArrayList::findLast(int numToFind){
    int foundNumIndex = 0;
    for (int i = 0; i < currCapacity +1; i++){

        if (array[i] == numToFind){
            foundNumIndex = i;
        }
    }

    return foundNumIndex-1;
}

int ArrayList::findMaxIndex(){
    if (currCapacity < 1){
        throw std::out_of_range("In findMaxIndex, List must have items");
    }
    else{
        int maxValue = array[1];
        int indexToReturn = 0;
        for (int i = 1; i <= currItemCount; i++){
            if(array[i] > maxValue){
                maxValue = array[i];
                indexToReturn = i -1;
            }
        }
        return indexToReturn;
    }
}

void ArrayList::insertAtFront(int itemToAdd){

    if(currItemCount == currCapacity){
        doubleCapacity(currCapacity, array);
        insertAtFront(itemToAdd);
    }
    else {
        for(int i = currItemCount; i >= 0; i--){
            array[i+1] = array[i];
        }
        array[1] = itemToAdd;
        currItemCount++;
    }
}

void ArrayList::insertAt(int itemToAdd, int index){
    if(index < 0 || index > currItemCount){
        throw std::out_of_range("Bad index given to insertAt: " + std::to_string(index));
    }

    if (currItemCount == currCapacity) {
        doubleCapacity(currCapacity, array);
        insertAt(itemToAdd, index);
    }
    else {
        currItemCount++;
        for (int i = currItemCount; i >= index; i--) {
            array[i+1] = array[i];
        }
        array[index+1] = itemToAdd;
    }
}

int ArrayList::removeValueAtEnd(){
    if (array[currItemCount-1] == 0) {
        throw std::out_of_range("Array is empty");
    }
    else {
        int numToReturn = array[currItemCount-1];
        array[currItemCount-1] = 0;
        currItemCount -= 1;
        return numToReturn;
    }
}

int ArrayList::removeValueAtFront(){
    if (array[0] == 0) {
        throw std::out_of_range("Array is empty");
    }
    else {
        int numToReturn = array[1];
        array[1] = NULL;

        for (int i = 0 ; i <= currItemCount; i++) {
            array[i] = array[i + 1];
        }
        currItemCount - 1;
        return numToReturn;
    }
}

int ArrayList::removeValueAt(int index){
    if (index > currItemCount || index < currItemCount) {
        throw std::out_of_range("Bad index given to insertAt: " + std::to_string(index));
    }
    else {
        int numToReturn = array[index];
        array[index] = 0;

        for (int i = index; i < currItemCount; i++) {
            array[i] = array[i + 1];
        }
        currItemCount -= 1;
        return numToReturn;
    }
}