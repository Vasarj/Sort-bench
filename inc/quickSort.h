/**
*
* @author Alexander Arzhanov
* @version 21/10/17
*
* Quick Sort
* ´´´´´´´´´´
*  Characteristics:
*     - best case: O( n log(n) )
*     - average case: O( n log(n) )
*     - worst case: O( n^2 )
*     - memory complexity: O( log(n) ) [ average case ]
*     - stable: no (if most efficient)
*
*  Discussion:
*     - constant factor is better than in Merge Sort,
*       thus usually outperforming most of other algorithms
*     - 'worst' case scenario can be usually avoided
*       by randomization of the 'pivot' choice
*     - Quick Sort is similar to Selection Sort,
*       where 'worst' case partitioning is avoided
*
**/

#pragma once

#include "util.h" // NEED: swap(..)

template<typename T>
int partition(T* a, int lo, int hi) {

	T piv = a[hi];
	int p = lo;

	for (int i = lo; i < hi; i++)
		if (a[i] <= piv) swap(a[i], a[p++]);

	swap(a[p], a[hi]);

	return p;

}

template<typename T>
void qSort(T* a, int lo, int hi) {

	if (lo >= hi) return;

	int p = partition(a, lo, hi);

	qSort(a, lo, p - 1);
	qSort(a, p + 1, hi);

}

// Wrapper for qSort
template<typename T>
void quickSort(T* a, const int n) {

	qSort(a, 0, n - 1);

}
