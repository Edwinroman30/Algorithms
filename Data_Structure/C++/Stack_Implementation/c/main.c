#include <stdio.h> // This library is the same in C++ <iostream>
#include <stdlib.h>
/* 
    TO RUN THIS CODE YOU WILL NEED A COMPILER PREINSTALLED. 
    c ./main.c -o outputname || gcc ./main.c -o outputname
 */

// Using Structured & Procedured Programming Paradigms

//Element Definition.
typedef struct{
    struct Element* next_element;
    char* name; //Cause in C we dont have string 
}Element;


//Important variable in our Stack DS
Element* LAST_ELEMENT = NULL;



//Stack method definition:

void push(Element* newElementToInsert){

    newElementToInsert->next_element = NULL;

    if(LAST_ELEMENT == NULL){
        LAST_ELEMENT = newElementToInsert;
    }else{
        newElementToInsert->next_element = LAST_ELEMENT;
        LAST_ELEMENT = newElementToInsert;
    }
}

Element* pop(){

    if(LAST_ELEMENT == NULL){
        printf("The stack is empty.");
        return NULL;
    }

    Element* helperElement = LAST_ELEMENT;
    LAST_ELEMENT = LAST_ELEMENT->next_element;
    return helperElement; //It responsability of the client to free up this variable from the heap memory.
}


int main(){

    //An stack of books:

    Element* firstBook = malloc(sizeof(Element));
    firstBook->name = "Introduction to C++, second Edition.";
    Element* secondBook = malloc(sizeof(Element));
    secondBook->name = "Designing Data intensive application.";
    Element* thirdBook = malloc(sizeof(Element)); // the last but not least
    thirdBook->name = "Learning Domain Driven Design, Oreally Media.";

    // Lets insert into our DS
    push(firstBook);
    push(secondBook);
    push(thirdBook);

    //Printing its values:
    printf("Stack output:");

    Element* i = pop();

    while (i != NULL)
    {
        printf(i->name);
        free(i);
        i = pop();
    }
    

    printf("Memory cleared!!");
    return 0;
}