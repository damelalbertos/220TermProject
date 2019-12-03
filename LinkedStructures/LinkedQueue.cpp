//
// Created by Toby Dragon on 10/24/17.
//
#include "LinkedQueue.h"

//Creates an empty queue
LinkedQueue::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
LinkedQueue::LinkedQueue(const LinkedQueue& queueToCopy){
    while(queueToCopy.front != queueToCopy.end || queueToCopy.front != nullptr){
        enqueue(queueToCopy.front->getItem());
    }
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& queueToCopy){
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
LinkedQueue::~LinkedQueue(){
    while(isEmpty()){
        dequeue();
    }
}


//adds an item to the end of the queue
void LinkedQueue::enqueue(std::string item){
    LinkedNode* newNode = new LinkedNode(item);
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
std::string LinkedQueue::dequeue(){
    if(front == nullptr){
        throw std::out_of_range("Queue is empty");
    }
    else if(front == end){
        std::string tempItem = front->getItem();
        delete front;
        front = nullptr;
        end = nullptr;
        return tempItem;
    }
    else{
        std::string tempItem = front->getItem();
        LinkedNode* tempPtr = front->getNext();

        delete front;

        front = tempPtr;
        return tempItem;
    }
}

//returns true if the queue has no items, false otherwise
bool LinkedQueue::isEmpty(){
    return front == nullptr;
}