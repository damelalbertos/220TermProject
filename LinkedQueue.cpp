//
// Created by Toby Dragon on 10/24/17.
//
#include "LinkedQueue.h"

//Creates an empty queue

template<class T>
LinkedQueue<T>::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
template<class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue& queueToCopy){
    while(queueToCopy.front != queueToCopy.end || queueToCopy.front != nullptr){
        enqueue(queueToCopy.front->getItem());
    }
}

template<class T>
LinkedQueue& LinkedQueue<T>::operator=(const LinkedQueue& queueToCopy){
    if(this != &queueToCopy){
        if(queueToCopy.front == nullptr){
            this->front = nullptr;
            this->end = nullptr;
        }
        else {
            this->front = new LinkedNode(queueToCopy.front->getItem());
            LinkedNode *frontNodeCopy = this->front;
            LinkedNode *nodeToCopy = queueToCopy.front;
            LinkedNode *endNodeCopy = nodeToCopy;

            while (endNodeCopy->getNext() != nullptr) {
                frontNodeCopy->setNext(new LinkedNode(endNodeCopy->getNext()->getItem()));
                endNodeCopy = endNodeCopy->getNext();
                this->end = frontNodeCopy->getNext();
            }
        }
    }
    return *this;
}

//Destructor
template<class T>
LinkedQueue<T>::~LinkedQueue(){
    while(isEmpty()){
        dequeue();
    }
}


//adds an item to the end of the queue
template<class T>
void LinkedQueue<T>::enqueue(T item){
    LinkedNode<T>* newNode = new LinkedNode<T>(item);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        end->setNext(newNode);
        end = newNode;
    }
}

//takes an item off the front of the queue and returns it
//throws out_of_range exception if the queue is empty
template<class T>
T LinkedQueue<T>::dequeue(){
    if(front == nullptr){
        throw std::out_of_range("Queue is empty");
    }
    else if(front == end){
        T tempItem = "Queue is empty";
        delete front;
        front = nullptr;
        end = nullptr;
        return tempItem;
    }
    else{
        LinkedNode* tempPtr = front->getNext();

        delete front;

        front = tempPtr;
        std::string tempItem = front->getItem();
        return tempItem;
    }
}

//todo
template<class T>
void LinkedQueue<T>::remove(T itemToRemove){
    if(front == nullptr){
        throw std::out_of_range("Queue is empty");
    }
    end = front;
    while (end->getNext() != nullptr){
        if(end->getItem() == itemToRemove){
            LinkedNode* tempPtr = end;

            delete end;
        }
    }
}


//returns true if the queue has no items, false otherwise
template<class T>
bool LinkedQueue<T>::isEmpty(){
    return front == nullptr;
}