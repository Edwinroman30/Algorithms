#include <iostream>
#include "Queue.h"

void printingStringRepresentation(Queue* theQueue);

int main(){

    //My elements (Remember, we need to free up all memory allocation that we did.)
    Element* thesis = new Element("Optimization of embeded devices signal with C++.pdf");
    Element* article = new Element("Understanding how C++ and C pointers work.pdf");
    Element* article2 = new Element("How algorithms are impacting the way of computers works.docx");
    
    //My printer Queue
    Queue* myqueue = new Queue(); 
    
    myqueue->Enqueue(thesis);
    myqueue->Enqueue(article);
    myqueue->Enqueue(article2);

    printingStringRepresentation(myqueue);

    delete myqueue; //Also cleaning the space for the queue it self.

    return 0;
}

//This method run into the queue, print and free up safely each element.

void printingStringRepresentation(Queue* theQueue){

    Element* theElement = theQueue->Dequeue(); // Initialy the first element.

    std::cout << "Printting..." << std::endl;
    while(theElement != NULL){
        std::cout << theElement->getName() << std::endl;
        delete theElement;

        //Cause the theElement memory space was free up we can reuse this spaces.
        theElement = theQueue->Dequeue();
    }

}

// Written by Edwin Roman