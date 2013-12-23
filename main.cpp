#include <cstdlib>
#include <iostream>
#include "QuickSort.h"

using namespace std;

bool numberCompare (int i1, int i2) {
    if (i1 <= i2) {
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, char *argv[])
{
    int numberArray [] = {9,6,4,6,2,1,3,1,3,5,4,7,8,9,6,2,2,1,4,5,8,9,3,0,4,7,5,2,0,3,5,4}; //size 32
    QuickSort <int> qSort (sizeof(numberArray)/sizeof(int), numberArray, numberCompare);
    qSort.Sort ();
    for (int i = 0; i < 32;i++) {
     std::cout << numberArray [i] << " ";   
    }
    std::cout << std::endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

