//
// Created by Toby Dragon on 10/22/17.
//

#ifndef STACKSANDQUEUES_QUEUE_H
#define STACKSANDQUEUES_QUEUE_H

#include <string>
#include <stdexcept>
#include "LinkedNode.h"

/**
 * Represents a FIFO data structure (First In First Out). Picture a line
 * to wait for something (first person in is the first person out)
 */
template<class T>
class LinkedQueue {
private:
    LinkedNode<T>* front;
    LinkedNode<T>* end;

public:
    
    //Creates an empty queue
    LinkedQueue();

    //Copy Constructor
    LinkedQueue(const LinkedQueue& queueToCopy);

    //Destructor
    ~LinkedQueue();
    
    //adds an item to the end of the queue
    void enqueue(T item);

    //takes an item off the front of the queue and returns it
    //throws out_of_range exception if the queue is empty
    T dequeue();

    /**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    std::string toString();

    /**
     * Searches an int array for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
    int find(T itemToFind);

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    void removeValueAt(int index);

    //returns true if the queue has no items, false otherwise
    bool isEmpty();

};

#endif //STACKSANDQUEUES_QUEUE_H
