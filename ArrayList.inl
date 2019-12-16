//
// Created by Matt on 10/15/2019.
//

#include "ArrayList.h"

template<class T>
ArrayList<T>::ArrayList(int initialCapacity) {
    if (initialCapacity < 1) {
        throw std::invalid_argument("In ArrayList constructor, size must be > 0");
    }
    else {
        array = new T[initialCapacity];
        currItemCount = 0;
        currCapacity = initialCapacity;
    }
}

//Copy Constructor
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& arrayListToCopy){
    for (int i = 0; i < currCapacity; i++) {
        this->array[i] = arrayListToCopy.array[i];
    }
    this->currItemCount = arrayListToCopy.currItemCount;
    this->currCapacity = arrayListToCopy.currCapacity;
}

//Overloaded Assignment Operator
template<class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& arrayListToCopy){
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
template<class T>
ArrayList<T>::~ArrayList(){
    delete array;
    array = nullptr;
}

template<class T>
void ArrayList<T>::doubleCapacity(int capacity, T* oldArray){
    T* doubledArr = new T[capacity*2];
    for(int i =0; i <= capacity; i++){
        doubledArr[i] = oldArray[i];
    }
    delete[] oldArray;
    this->array = doubledArr;
}

template<class T>
void ArrayList<T>::insertAtEnd(T itemToAdd){
    if(currCapacity == currItemCount && currItemCount != 0){
        doubleCapacity(currCapacity, array);
        array[currItemCount]=itemToAdd;
        currItemCount++;
    }
    else{
        array[currItemCount]=itemToAdd;
        currItemCount++;
    };

}

template<class T>
T ArrayList<T>::getValueAt(int index){
    if (index < 0 || index > currItemCount) {
        throw std::out_of_range("Bad index given to getValueAt: "+ std::to_string(index));
    }
    else {
        return array[index];
    }
}

template<class T>
std::string ArrayList<T>::toString(){

    return toString(array+1,currItemCount);
}

template<class T>
bool ArrayList<T>::isEmpty(){
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

template<class T>
int ArrayList<T>::itemCount(){
    return currItemCount;
}

template<class T>
void ArrayList<T>::clearList(){
    for(int i =1; i < currCapacity; i++){
        array[i] = NULL;
    }
    currItemCount = 0;
}

template<class T>
int ArrayList<T>::find(T itemToFind){
    int foundNumIndex = -1;

    for (int i = 0; i < currItemCount; i++) {
        T current = array[i];
        if (array[i] == itemToFind) {
            foundNumIndex = i;
            return foundNumIndex;
        }
    }
    return foundNumIndex;
}

template<class T>
int ArrayList<T>::findLast(T itemToFind){
    int foundNumIndex = 0;
    for (int i = 0; i < currCapacity +1; i++){

        if (array[i] == itemToFind){
            foundNumIndex = i;
        }
    }

    return foundNumIndex-1;
}


template<class T>
void ArrayList<T>::insertAtFront(T itemToAdd){

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

template<class T>
void ArrayList<T>::insertAt(T itemToAdd, int index){
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

template<class T>
T ArrayList<T>::removeValueAtEnd(){
    if (array[currItemCount-1] == 0) {
        throw std::out_of_range("Array is empty");
    }
    else {
        std::string itemToReturn = array[currItemCount-1];
        array[currItemCount-1] = 0;
        currItemCount -= 1;
        return itemToReturn;
    }
}

template<class T>
T ArrayList<T>::removeValueAtFront(){
    if (array[0] == 0) {
        throw std::out_of_range("Array is empty");
    }
    else {
        std::string itemToReturn = array[1];
        array[1] = NULL;

        for (int i = 0 ; i <= currItemCount; i++) {
            array[i] = array[i + 1];
        }
        currItemCount - 1;
        return itemToReturn;
    }
}

template<class T>
T ArrayList<T>::removeValueAt(int index){
    if (index > currItemCount || index < 0) {
        throw std::out_of_range("Bad index given to insertAt: " + std::to_string(index));
    }
    else {
        T itemToReturn = array[index];

        currItemCount -= 1;
        for (int i = index; i < currItemCount; i++) {
            array[i] = array[i + 1];
        }

        return itemToReturn;
    }
}