/**
*
* @author Alexander Arzhanov
* @version 21/10/17
*
* Bubble Sort
* ´´´´´´´´´´´
*  Characteristics:
*     - best case: O( n )  [if already sorted & implemented with *extra* flag]
*     - average case: O( n^2 )
*     - worst case: O( n^2 )
*     - memory complexity: O( 1 )
*     - stable: yes
*
*  Discussion:
*     - 'bubble up' largest elements to the top by consecutive swappings
*     - worse than 'worst' and 'average' cases of most other algorithms
*     - only advantage is for 'best' case (exception: Insert Sort), as
*       as Bubble Sort has to 'pass' the array only once
*
**/


#pragma once

#include "util.h" // NEED: swap(..)

template<typename T>
void bubbleSort(T* a, int n) {

   for (int i = 0; i < n - 1; i++) {

      bool flag = true; // *extra*

      for (int j = 0; j < n - i - 1; j++)
         if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
            flag = false; // *extra*
         }

      if (flag) break; // *extra*

   }
}