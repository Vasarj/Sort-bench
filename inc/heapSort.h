/**
*
* @author Alexander Arzhanov
* @version 21/10/17
*
* Heap Sort
* ´´´´´´´´´
*  Characteristics:
*     - best case: O( n log(n) ) 
*     - average case: O( n log(n) ) 
*     - worst case: O( n log(n) ) 
*     - memory complexity: O( 1 )
*     - stable: no
*
*  Discussion:
*     - relies on complete binary trees (heaps)
*     - while generally less favorable than Quick Sort, 
*       its 'worst' case runtime is relatively good
*
**/

#pragma once

#include "util.h" // NEED: swap(..)

template<typename T>
void heapify(T* a, int n, int i) {

    int m = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[m])
        m = l;

    if (r < n && a[r] > a[m])
        m = r;

    if (m != i)
    {
        swap(a[i], a[m]);

        heapify(a, n, m);
    }

}

template<typename T>
void heapSort(T* a, int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);

        heapify(a, i, 0);
    }

}