/*
  Name: Main
  Author: Matthew AhSam
  Date: 27/12/13 15:03
  Description: Test Main for QuickSort.h
*/
#include <cstdlib>
#include <iostream>
#include "QuickSort.h"

using namespace std;

int numberCompare (int i1, int i2) {
    if (i1 < i2) {
        return -1;
    } else {
        if (i1 == i2) {
            return 0;
        } else {
            return 1;
        }
    }
}

int main(int argc, char *argv[])
{
    int numberArray [] = {27,19,5,25,13,2,15,26,16,6,11,1,4,12,18,7,29,10,21,30,23,22,8,14,17,3,20,24,9,28}; //size 32
    QuickSort <int> qSort (sizeof(numberArray)/sizeof(int), numberArray, numberCompare);
    qSort.Sort (qSort.fullSizeOfArray, qSort.fullArray);
    for (int i = 0; i < qSort.fullSizeOfArray;i++) {
     std::cout << numberArray [i] << " ";   
    }
    std::cout << std::endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

