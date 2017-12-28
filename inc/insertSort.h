/**
*
* @author Alexander Arzhanov
* @version 21/10/17
*
* Insertion Sort
* 创创创创创创创
*  Characteristics:
*     - best case: O( n )
*     - average case: O( n^2 )
*     - worst case: O( n^2 )
*     - memory complexity: O( 1 )
*     - stable: yes
*
*  Discussion:
*     - while could be written as three-line can be more
*       efficient than Selection and Bubble sort (even 
*       Quick Sort sometimes) in cases of small arrays
*     - divides array into 'sorted' and 'unsorted',
*       picks a 'key' on the division line, and inserts 
*       it into its place in 'sorted' part of array
*
**/

#pragma once

template<typename T>
void insertSort(T* a, int n) {

   for (int i = 1; i < n; i++) {

      T t = a[i];
      int j = i;

      while (j > 0 && t < a[j - 1]) {
         a[j] = a[j - 1];
         j--;
      }

      a[j] = t;

   }

}