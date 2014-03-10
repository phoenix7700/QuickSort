#ifndef QUICKSORT_H
#define QUICKSORT_H
/*
  Name: QuickSort
  Author: Matthew AhSam
  Date: 12/17/2013 04:04
  Description: QuickSort.h
  Requirements: Comparison function - int (*compare) (T,T) - T1 < T2 return -1 T1 == T2 return 0 T1 > T2 return 1;
                Overloaded = operator - Makes use of = operator as a copy
                
Example compare function
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
*/
#include <stdlib.h>

template <class T>
class QuickSort {
    public:
        //Varibale
        T * fullArray;       
        int fullArraySize;
    
        int (*compare) (T,T); //T1 <= T2 return true, T1 > T2 return false
                
        //Functions
                QuickSort(int,T *,int (*)(T,T)); // int (*compare) (T,T) function pointer should be in callback function for comparisons
                ~QuickSort();    
        T *     Sort();
        void    DisplayArray (int,T *);
    
    private: 
        T *     SortPriv (int, T *);
  
};

template <class T>
void QuickSort <T>::DisplayArray (int arraySize, T * array) {
    std::cout << std::endl << "Array: {";
    std::cout << array [0];
    for (int i = 1; i < arraySize; i++) {
        std::cout << ", " << array [i] ;
    }
    std::cout << "}" << std::endl;
}

template <class T>
T * QuickSort <T>::Sort () {
    return SortPriv(fullArraySize, fullArray);
}

template <class T>
T * QuickSort <T>::SortPriv (int arraySize, T * sortArray){
    T * leftSelector = &sortArray [0];
    int leftCounter = 0;
    T * rightSelector = &sortArray [arraySize-1];
    int rightCounter = arraySize-1;
    int seed = rand()%arraySize;
    T  pivot = sortArray[seed];//Random pivot
    T temp;
    bool hasMoved;
    int movedCounter = 0;
    std::cout << std::endl << "START SORT FUNCTION!" << std::endl << "Pivot " << pivot << std::endl << "Array Size: " << arraySize << std::endl;
    
        while (leftSelector != rightSelector) {
            hasMoved = false;
            DisplayArray(fullArraySize,fullArray);
            std::cout << "Left " << *leftSelector << " ";
            while (1 == (compare (pivot,*leftSelector))) { //Keep getting next element while pivot is greater than left selector
                if (leftSelector == rightSelector){
                    break;
                }
                leftCounter++;
                leftSelector = &sortArray [leftCounter];
                std::cout << "Picking LEFT: " << *leftSelector << " ";
                hasMoved = true;
            }
            std::cout << std::endl << "Right " << *rightSelector << " ";

            while (-1 == (compare (pivot,*rightSelector))) { //Keep getting next element while pivot is less than right selector
                if (leftSelector == rightSelector){
                    break;
                }
                rightCounter--;
                rightSelector = &sortArray [rightCounter];
                std::cout << "Picking RIGHT: " << *rightSelector << " ";
                hasMoved = true;
            }
            temp = *leftSelector;
            *leftSelector = *rightSelector;
            *rightSelector = temp;
            if (hasMoved == false && *leftSelector == *rightSelector) { //If there are multiples of the chosen pivot this if statement 
                if(leftSelector+1 == rightSelector){
                    break; //Array is sorted if the pivots are adjacent
                }
                if (leftSelector == &sortArray[0 + movedCounter]) { //If leftselector is farthest left move to next element
                    leftSelector++;
                } else {
                    //Switch leftSelector with far left position
                    temp = sortArray[0 + movedCounter];
                    sortArray[0 + movedCounter] = *leftSelector;
                    *leftSelector = temp;
                }
                
                if (rightSelector == &sortArray [arraySize - 1 - movedCounter]) { //If rightselector is farthest right move to next element
                    rightSelector--;   
                } else {
                    //Switch rightSelector with far right position
                    temp = sortArray [arraySize - 1 - movedCounter];
                    sortArray [arraySize-1-movedCounter] = *rightSelector;
                    *rightSelector = temp;
                }
                
                movedCounter++;
            }
            DisplayArray(fullArraySize,fullArray);
            //system("PAUSE");
        }
        //Put pivots back in middle
        T endPoint = *leftSelector;
        for (int i = 0 ;i < movedCounter; i++) {
            if (endPoint < pivot){
                T * tempPointer = leftSelector - i;
                temp = *tempPointer;
                *tempPointer = sortArray [0 + i];
                sortArray [0 + i] = temp;
                
                tempPointer = leftSelector + i + 1;
                temp = *tempPointer;
                *tempPointer = sortArray [arraySize - 1 - i];
                sortArray [arraySize - 1 - i] = temp;  
            } else {
                if (endPoint == pivot) {
                    T * tempPointer = leftSelector - i - 1;
                    temp = *tempPointer;
                    *tempPointer = sortArray [0 + i];
                    sortArray [0 + i] = temp;
                
                    tempPointer = leftSelector + i + 1;
                    temp = *tempPointer;
                    *tempPointer = sortArray [arraySize - 1 - i];
                    sortArray [arraySize - 1 - i] = temp;  
                } else { // *leftSelector > pivot
                    T * tempPointer = leftSelector - i - 1;
                    temp = *tempPointer;
                    *tempPointer = sortArray [0 + i];
                    sortArray [0 + i] = temp;
                    
                    tempPointer = leftSelector + i;
                    temp = *tempPointer;
                    *tempPointer = sortArray [arraySize - 1 - i];
                    sortArray [arraySize - 1 - i] = temp;
                }
                
            }
        }
        DisplayArray(fullArraySize,fullArray);
        //system("PAUSE");
        if (arraySize > 2) {
            T * sizePointer = &sortArray [0];
            int countSize = 0;
            while (compare(pivot,*sizePointer) != 0) {
                sizePointer++;
                countSize++;
            }
            if (countSize >0) {
                SortPriv(countSize,sortArray);
            }
            sizePointer = &sortArray [arraySize - 1];
            countSize = 0;
            while(compare(pivot,*sizePointer) != 0) {
                sizePointer--;
                countSize++;
            }
            sizePointer++;
            if (countSize >0) {
                SortPriv(countSize,sizePointer);
            }
        }
    return sortArray;
}


template <class T>      
QuickSort <T>::QuickSort(int arraySize, T * arrayPointer, int (*typeCompare) (T,T)) {
    fullArraySize = arraySize;
    fullArray = arrayPointer;
    compare = typeCompare;
}
             
template <class T>
QuickSort <T>::~QuickSort () {
                            
}

#endif
      
