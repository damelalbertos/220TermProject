//
// Created by Toby Dragon on 10/24/17.
//

#include "LinkedStack.h"

//Creates an empty stack
LinkedStack::LinkedStack(){
    top = nullptr;
}

//copy constructor
LinkedStack::LinkedStack(const LinkedStack& stackToCopy){
    LinkedNode* newTop = nullptr;
    while(stackToCopy.top->getNext() != nullptr){
        push(stackToCopy.top->getItem());
    }
}

LinkedStack& LinkedStack::operator=(const LinkedStack& stackToCopy){
    if(this != &stackToCopy){
        this->top = stackToCopy.top;
    }
    return *this;
}

//destructor
LinkedStack::~LinkedStack(){
    while(isEmpty()){
        pop();
    }
}

//puts an item onto the top of the stack
void LinkedStack::push (std::string item){
    LinkedNode* newNode = new LinkedNode(item);
    newNode->setNext(top);
    top = newNode;
}

//takes the item off the top of the stack and returns it
//throws out_of_range exception if the stack is empty
std::string LinkedStack::pop(){
    if(top == nullptr){
        throw std::out_of_range("Stack is empty");
    }
    else{
        std::string tempItem = top->getItem();
        LinkedNode* tempPtr = top->getNext();

        delete top;
        top = tempPtr;
        return tempItem;
    }
}

//returns true if the stack has no items, false otherwise
bool LinkedStack::isEmpty(){
    return top == nullptr;
}

