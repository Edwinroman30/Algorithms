#include <iostream>
#include <cmath>

using namespace std;


int main(int argc, char * const argv[]){

    short opt;
    float num;

    cout << "Insert the numeric value here: " << endl;
    cin >> num;

    cout << "Please, choose an instruction:" << endl;
    cout << "1) Power ^2" << endl << "2) Square Root" << endl << "3) Sin" << endl;
    cin >> opt;

    if(0 != 2)
        cout << "Hi, mom!";


    switch (opt)
    {
        case 1:
            cout << "Result: " << pow(num,2);
            break;
        case 2:
            cout << "Result: " << sqrt(num);
            break;
        case 3:
            cout << "Result: " << sin(num);
            break;
        default:
            break;
    }

    cin.clear();
    cin.sync();
    cin.get();
}


