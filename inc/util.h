/**
*
* @author Alexander Arzhanov
* @version 21/10/17
*
* Utilities 
* ´´´´´´´´´
*  Contains templates:
*     - swap(..)          : swap two items in an array
*     - printArray(..)    : pretty printing for an array
*     - copyArr(..)       : copy one array into the other
*     - genRandom(..)     : generate a random number in the given range
*
**/



#pragma once

#include <iostream>
#include <random>  // NEED: random_device, mt19937

template<typename T> 
inline void swap(T& a, T& b) {

	T tmp(a);
	a = b;
	b = tmp;

}

template<typename T>
void printArray(T* arr, const int n) {

	for (int i = 0; i < n; i++) 
		std::cout << ( (i % 5 ) ? " " : "\n " ) << arr[i];

	std::cout << std::endl;

}

template<typename T>
void copyArr(T* a, T* b, const int n) {

   for (int i = 0; i < n; i++)
      a[i] = b[i];

}

// NOTE: general case --> have to cast return type
template<typename T>
static T genRandom(const T& begin, const T& end) {
   static std::random_device rd;
   static std::mt19937 re(rd( ));
   std::uniform_real_distribution<double> range(begin, end);

   return range(re);

}
