#include <iostream>
#include "Stack.h"

void riddingTheStackElements(Stack* myStack );

int main(){

   //An stack of books:
    Element* firstBook = new Element("(1)Introduction to C++, second Edition.");
    Element* secondBook= new Element("(2)Designing Data intensive application.");
    Element* thirdBook = new Element("(3)Learning Domain Driven Design, Oreally Media."); // the last but not least

    // Stack Data Structure
    Stack* bookStack = new Stack();
    bookStack->Push(firstBook);
    bookStack->Push(secondBook);
    bookStack->Push(thirdBook);

    riddingTheStackElements(bookStack);
    delete bookStack;

   return 0;
};


void riddingTheStackElements(Stack* myStack){

    if(myStack == NULL || myStack == nullptr){
        std::cout << "The Stack Data Structure is empty bro!" << std::endl;
    }

    Element* helperElement = myStack->Pop();

    while (helperElement != NULL)
    {
        std::cout << helperElement->getName() << std::endl;
        delete helperElement;
        helperElement = myStack->Pop();
    }

}