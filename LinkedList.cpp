//
// Created by Toby Dragon on 10/30/18.
//

#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList(){
    front = nullptr;
    end = nullptr;
    currItemCount = 0;
}

//Destructor
template<class T>
LinkedList<T>::~LinkedList(){
    clearList();
}

template<class T>
void LinkedList<T>::insertAtEnd(T itemToAdd){
    LinkedNode<T>* newNode = new LinkedNode(itemToAdd);
    if(front == nullptr && end == nullptr){
        end = newNode;
        front = end;
        currItemCount++;
    }
    else{
        end->setNext(newNode);
        end = newNode;
        currItemCount++;
    }
}

template<class T>
int LinkedList<T>::getValueAt(int index){
    if(index < 0){
        throw std::out_of_range("INDEX OUT OF RANGE");
    }
    else {
        int valueToReturn;
        int count = 0;
        while(count != index) {
            end = end->getNext();
            count++;
        }
        valueToReturn = end->getItem();

        //resets end to the proper node
        while(end->getNext() != nullptr){
            end = end->getNext();
        }
        return valueToReturn;
    }
}

template<class T>
std::string LinkedList::toString(){
    std::string stringToReturn;
    end = front;
    if(front == nullptr && end == nullptr){
        return "{}";
    }
    else{
        stringToReturn += "{";
        while(end->getNext() != nullptr){
            stringToReturn += std::to_string(end->getItem());
            stringToReturn +=", ";
            end = end->getNext();
        }
        stringToReturn += std::to_string(end->getItem());
        stringToReturn += "}";
    }

    //resets end to the proper node
    while(end->getNext() != nullptr){
        end = end->getNext();
    }

    return stringToReturn;
}

template<class T>
bool LinkedList<T>::isEmpty(){
    if(front == nullptr && currItemCount == 0){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
int LinkedList<T>::itemCount(){
    return currItemCount;
}

template<class T>
void LinkedList<T>::clearList(){
    while(front->getNext() != nullptr) {
        end = front->getNext();
        delete front;

    }
    front = nullptr;
    end = nullptr;
    currItemCount = 0;
}

template<class T>
int LinkedList<T>::find(T itemToFind){
    int indexToReturn = -1;
    end = front;
    while(end->getItem() != itemToFind){
        indexToReturn++;
        end = end->getNext();
    }

    //resets end to the proper node
    while(end->getNext() != nullptr){
        end = end->getNext();
    }

    return indexToReturn;
}

template<class T>
int LinkedList<T>::findLast(T itemToFind){
    int indexToReturn = -1;
    end = front;
    while(end->getItem() != itemToFind){
        end = end->getNext();
        indexToReturn ++;
    }
    return indexToReturn;
}

template<class T>
int LinkedList<T>::findMaxIndex(){
    int maxValue = front->getItem();
    int indexToReturn = 0;
    end = front;

    if(front == nullptr){
        throw std::out_of_range("list empty");
    }
    else{
        while (end->getNext() != nullptr) {
            if (end->getItem() > maxValue) {
                maxValue = end->getItem();
                indexToReturn++;
            }
            else {
                end = end->getNext();
                indexToReturn++;
            }
        }
    }
    //resets end to the proper node
    while(end->getNext() != nullptr){
        end = end->getNext();
    }
    return indexToReturn;
}

template<class T>
void LinkedList<T>::insertAtFront(T itemToAdd){
    LinkedNode<T>* newNode = new LinkedNode(itemToAdd);
    if(front == nullptr && end == nullptr){
        front = newNode;
        end = newNode;
        currItemCount++;
    }
    else{
        end = front;
        front = newNode;
        front->setNext(end);
        currItemCount++;
    }
    //resets end to the proper node
    while(end->getNext() != nullptr){
        end = end->getNext();
    }
}

template<class T>
void LinkedList::insertAt(T itemToAdd, int index){
    end = front;
    if(index < 0 or index > currItemCount){
        throw std::out_of_range("index out of scope");
    }
    else {
        LinkedNode* newNode = new LinkedNode(itemToAdd);
        int count = 0;
        while (count != index) {
            end = end->getNext();
            count++;
        }
        newNode->setNext(end->getNext());
        end->setNext(newNode);
    }
    currItemCount++;

    while(end->getNext() != nullptr){
        end = end->getNext();
    }
}

template<class T>
int LinkedList<T>::removeValueAtEnd(){
    std::string valueToReturn;
    if(isEmpty()){
        throw std::out_of_range("list is empty");
    }
    else {
        valueToReturn = end->getItem();
        delete end;
        end = front;

        while(end->getNext() != nullptr){
            end = end->getNext();
        }
    }
    currItemCount--;
    return valueToReturn;
}

template<class T>
std::string LinkedList<T>::removeValueAtFront(){
    std::string valueToReturn;
    end = front->getNext();

    if(isEmpty()){
        throw std::out_of_range("list is empty");
    }
    else {
        valueToReturn = front->getItem();
        delete front;
        front = end;

        while(end->getNext() != nullptr){
            end = end->getNext();
        }
    }
    currItemCount--;
    return valueToReturn;
}

template<class T>
std::string LinkedList<T>::removeValueAt(int index){
    LinkedNode* nodeToLinkTo;
    std::string valueToReturn;
    int count = 0;
    end = front;

    if(index < 0 || index > currItemCount){
        throw std::out_of_range("INDEX OUT OF RANGE");
    }
    else {
        while(count != index) {
            end = end->getNext();
            count++;
        }
        //makes copy of value, holds onto next and then deletes the node to be removed
        valueToReturn = end->getItem();
        nodeToLinkTo = end->getNext();
        delete end;

        //iterates through to the point where the node was removed and sets next to the second half of the list to reconnect them
        while(end->getNext() != nullptr){
            end = end->getNext();
        }
        end->setNext(nodeToLinkTo);

        //resets end to the proper node
        while(end->getNext() != nullptr) {
            end = end->getNext();
        }

        currItemCount--;
        return valueToReturn;
    }
}