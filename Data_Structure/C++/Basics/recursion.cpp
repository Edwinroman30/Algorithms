#include <iostream>


int factorial_recv(int factor = 1){

    if(factor == 0 || factor == 1){
        std::cout << "*" << factor;
        return 1;
    }
    else{
        std::cout << "*" << factor;
        return factor * factorial_recv(factor - 1);
    }
}


int main(){

    /* 
        Initial Execution:
        [op1]    factorial_recv(3) =  3 * factorial_recv(3 - 1) = 3 * factorial_recv(2);
        [op2]    factorial_recv(2) =  2 * factorial_recv(2 - 1) = 2 * factorial_recv(1);
        [op3]    factorial_recv(1) =  1 * factorial_recv(1 - 1) = 1 * factorial_recv(0) = 1;

        Recursive returns execution:
        [op3] = 1
        [op2] = 2 * factorial_recv(1)  = 2 * [op1] = 2 * 1 = 2
        [0p1] = 3 * factorial_recv(2); = 3 * [op2] = 3 * 2 = 6
        6
     */

    int r = factorial_recv(3);
    std::cout << std::endl << "Result: " << r << std::endl;
    std::cin.get();

}