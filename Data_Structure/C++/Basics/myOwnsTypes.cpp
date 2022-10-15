#include <iostream>
#include <string>
using namespace std;

int main() {
	
    //defining my own dataType Names:
    
    typedef short CeroTo256;
    typedef char* BufferPtr; 
    
    char ptr = 'e'; 
    
    BufferPtr mybuffer = &ptr;
    CeroTo256 myvalue = 30;
    
    cout << mybuffer;
    cout << myvalue;

}
