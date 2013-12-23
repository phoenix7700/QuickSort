#ifndef QUICKSORT_H
#define QUICKSORT_H
/*
  Name: QuickSort
  Author: Matthew AhSam
  Date: 17/12/13 04:04
  Description: QuickSort.h
*/
#include <stdlib.h>

template <class T>
class QuickSort {
      public:
      //Varibale       
      T * sortArray;
      int sizeOfArray;
      T * pivot;
      bool (*compare) (T,T); //T1 <= T2 return true, T1 > T2 return false
            
      //Functions
      // bool (*comparison) (T,T) function pointer should be in callback function for comparisons
              QuickSort(int,T *,bool (*)(T,T));
              ~QuickSort();
      T       Sort();
      void    ChoosePivot();
        
};

template <class T>
T QuickSort <T>::Sort (){
T * leftSelector = &sortArray [0];
int leftCounter = 0;
T * rightSelector = &sortArray [sizeOfArray-1];
int rightCounter = sizeOfArray-1;
T temp;
ChoosePivot();
std::cout << "Pivot " << *pivot << std::endl;
    while (leftSelector != rightSelector) {
        std::cout << "Left " << *leftSelector << " ";
        while (!(compare (*pivot,*leftSelector))) { //Finds next element in array until leftSelector is bigger than or equal to pivot
            leftCounter++;
            leftSelector = &sortArray [leftCounter];
            //std::cout << *leftSelector << " ";
        }
        std::cout << std::endl << "Right " << *rightSelector << " ";
        while (compare (*rightSelector, *pivot)) { //Finds next element in array until right Selector is smaller than or equal to pivot
            rightCounter--;
            rightSelector = &sortArray [rightCounter];
            //std::cout << *rightSelector << " ";
        }
        temp = *leftSelector;
        *leftSelector = *rightSelector;
        *rightSelector = temp;
            system("PAUSE");
    }
}

template <class T>
void QuickSort <T>::ChoosePivot () {
int seed = rand()%sizeOfArray;
pivot = &sortArray[seed];
}

template <class T>      
QuickSort <T>::QuickSort(int arraySize, T * arrayPointer, bool (*typeCompare) (T,T)) {
sizeOfArray = arraySize;
sortArray = arrayPointer;
compare = typeCompare;
}
             
template <class T>
QuickSort <T>::~QuickSort () {
                        
}

#endif
      
