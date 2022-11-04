#ifndef Stack_H
#define Stack_H
#include "Element.h"
class Stack{
public:
    Stack();
    ~Stack();
    void Push(Element* elem);
    Element* Pop();
private:
    void setLastElement(Element* element){ _lastElement = element; }
    Element* getLastElement() { return _lastElement; }
    Element* _lastElement;
};
#endif