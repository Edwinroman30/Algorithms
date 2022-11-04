#include <iostream>
#include "Queue.h"

Queue::Queue() : _firstElement(NULL), _lastElement(NULL)
{

}

Queue::~Queue(){
    // Free
}

void Queue::Enqueue(Element* elementToInsert){
    elementToInsert->setElement(NULL); //Optional cause I did it in element definition :)

    if(_firstElement == NULL){
        _firstElement = elementToInsert;
        _lastElement = elementToInsert;
    }else{
        _lastElement->setElement(elementToInsert);
        _lastElement = elementToInsert;
    }

}

Element* Queue::Dequeue(){

    if(_firstElement == NULL){
        std::cout << "The Queue is empty!" << std::endl;
        return NULL;
    }

    Element* lastFirst = _firstElement;
    _firstElement = _firstElement->getNextElement();

    return lastFirst;
}