#include "Stack.h"
#include <iostream>

Stack::Stack(): _lastElement( NULL ){

}

Stack::~Stack(){}

void Stack::Push(Element* elem){

    elem->setUnderElement(NULL);

    if(_lastElement == NULL){
        _lastElement = elem;
        return;
    }

    elem->setUnderElement(_lastElement);
    _lastElement = elem;
}


 Element* Stack::Pop(){

    if(_lastElement == NULL){
        std::cout << "The stack is empty..." << std::endl;
        return NULL;
    }

    Element* helperElement = _lastElement;
    _lastElement = _lastElement->getUnderElement();

    return helperElement; //Note: The client that use this clase must be responsible of free it up from memory.
 }