#include <iostream>

using namespace std;
int dataInmemory = 30;
int* dataInmemoryPointer;


void pointerChecker(int* reference){
    //Changing the reference:
    *reference = *reference * 2;
    cout << "Value changed..." << endl;
}


void ridingAnArray(char* arrayPointer, short length){

    cout << "It size is: " << sizeof(arrayPointer) << endl;

    for(short i; i < length; i++){
        cout << "Position: " << arrayPointer[i] << endl; 
    }    

}


int main(){

    char myArray[4] = {'A','B','C','D'};

    dataInmemoryPointer = &dataInmemory;
    cout << "xyz Entertainment Present:" << endl;

    cout << "Memory Direction: "                << &dataInmemory       << endl;
    cout << "What the pointer allocation say: " << dataInmemoryPointer << endl;
    cout << endl;

    pointerChecker(dataInmemoryPointer);

    cout << "Value: " << dataInmemory  << endl;
    cout << "Space in memory: " << sizeof(dataInmemory) << endl;

    cout << "-------PROCESS 2--------" << endl;
    ridingAnArray(myArray, 4);

    cout << "Here it is: " << *dataInmemoryPointer << endl;
    free(dataInmemoryPointer);

    pointerChecker(dataInmemoryPointer);

    cin.get();
}