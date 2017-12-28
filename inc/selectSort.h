/**
*
* Selection Sort
* 创创创创创创创
*  Characteristics:
*     - best case: O( n^2 )
*     - average case: O( n^2 )
*     - worst case: O( n^2 )
*     - memory complexity: O( 1 )
*     - stable: no
*
*  Discussion:
*     - one of the most simplistic algorithms,
*       might be used with small arrays when
*       auxillary memory is limited
*     - performs worse than most other sorting methods
*
**/




#pragma once

#include "util.h" // NEED: swap(..)

template<typename T>
void selectSort(T* a, const int n) {

	for (int i = 0; i < n; i++) {

		int m = i;

		for (int j = i; j < n; j++) 
			if (a[j] < a[m]) m = j;

		swap(a[i], a[m]);

	}
}