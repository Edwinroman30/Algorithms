#ifndef Queue_H
#define Queue_H
#include "Element.h"
class Queue{
public:
    Queue();
    ~Queue();
    void Enqueue(Element* elementToInsert);
    Element* Dequeue();
private:
    Element* _firstElement;
    Element* _lastElement;
};
#endif