/**
*
* Merge Sort
* 创创创创创
*  Characteristics:
*     - best case: O( n log(n) ) [while O(n) for 'natural' implementation]
*     - average case: O( n log(n) )
*     - worst case: O( n log(n) )
*     - memory complexity: O( n )
*     - stable: yes
*
*  Discussion:
*     - divide up to sigle elements (trivial) and conquer (merging)
*     - in practice runtimes are ~twice as fast as Quick Sort
*     - its 'natural' implementation is part of the hybrid Tim Sort
*
**/

#pragma once

#include <memory> // NEED: unique_ptr

using std::unique_ptr;

template<typename T>
void merge(T* a, const int n, const int m) {

	unique_ptr<T[]> x(new T[n]);

	for (int i = 0, j = m, k = 0; k < n; k++) {
		x[k] = (i == m)      ? a[j++]
			 : (j == n)      ? a[i++]
			 : (a[i] < a[j]) ? a[i++]
			 :                 a[j++];
	}
	
	for (int i = 0; i < n; i++) a[i] = x[i];

}

template<typename T>
void mergeSort(T* a, const int n) {

	if (n < 2) return;

	const int m = n / 2;

	mergeSort(a, m);
	mergeSort(a + m, n - m);

	merge(a, n, m);
}