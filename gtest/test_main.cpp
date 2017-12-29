/**
*
* @author Alexander Arzhanov
* @version 21/10/17
*
* Googletest Unit Testing
* ´´´´´´´´´´´´´´´´´´´´´´´
*     - Automated Unit Testing within googletest framework
*     - Two test suites included: 
*           -> RandomArrayTest:       6 test cases
*           -> PredefinedArrayTest:   6 test cases
*
**/

#include <iostream>

#include "gtest/gtest.h"

#include "../inc/util.h"

#include "../inc/bubbleSort.h"
#include "../inc/heapSort.h"
#include "../inc/insertSort.h"
#include "../inc/mergeSort.h"
#include "../inc/quickSort.h"
#include "../inc/selectSort.h"

using std::cout;
using std::endl;

// Testing with randomly generated numbers
class RandomArrayTest : public testing::Test
{
   public:
   
   static const int SIZE = 1000;
   double* testArr;
   
   private:
   
   virtual void SetUp() override {
      
      testArr = new double[SIZE];
       
      for (int i = 0; i < SIZE; i++) {
         testArr[i] = genRandom(-100.0, 100.0);   // FROM: util.h
      }
       
      cout << "[  SET UP  ] Input random array of size " << SIZE << " generated" << endl;
      
   }

   virtual void TearDown() override {
      
      delete[] testArr;
      cout << "[   CLEAN  ] Tear down test environment" << endl;
      
   }
};

// Testing with pre-defined array
class PredefinedArrayTest : public testing::Test
{
   public:
   
   static const int SIZE = 10;
   int* testArr;
   
   private:
   
   virtual void SetUp() override {
      
      testArr = new int[SIZE] { 0, 0, 5, 5, 5, 7, 7, 7, 7, 0 };
       
      cout << "[  SET UP  ] Input predefined array of size " << SIZE << " generated" << endl;
      
   }

   virtual void TearDown() override {
      
      delete[] testArr;
      cout << "[   CLEAN  ] Tear down test environment.." << endl;
      
   }
};




//
// -------------- RANDOM TESTS ----------------
//

// Test #1
TEST_F(RandomArrayTest, bubbleSort_Test) {
  
   // Sort
   bubbleSort(testArr, SIZE);

   // Test
   for (size_t i = 1; i < SIZE; i++)   
      ASSERT_LE(testArr[i-1], testArr[i]);
   
}

// Test #2
TEST_F(RandomArrayTest, heapSort_Test) {
  
   // Sort
   heapSort(testArr, SIZE);
   
   // Test
   for (size_t i = 1; i < SIZE; i++)    
      ASSERT_LE(testArr[i-1], testArr[i]);
   
}

// Test #3
TEST_F(RandomArrayTest, insertSort_Test) {
  
   // Sort
   insertSort(testArr, SIZE);
   
   // Test
   for (size_t i = 1; i < SIZE; i++)    
      ASSERT_LE(testArr[i-1], testArr[i]);
   
}

// Test #4
TEST_F(RandomArrayTest, mergeSort_Test) {
  
   // Sort
   mergeSort(testArr, SIZE);
   
   // Test
   for (size_t i = 1; i < SIZE; i++)    
      ASSERT_LE(testArr[i-1], testArr[i]);
   
}

// Test #5
TEST_F(RandomArrayTest, quickSort_Test) {
  
   // Sort
   quickSort(testArr, SIZE);
   
   // Test
   for (size_t i = 1; i < SIZE; i++)    
      ASSERT_LE(testArr[i-1], testArr[i]);
   
}

// Test #6
TEST_F(RandomArrayTest, selectSort_Test) {
  
   // Sort
   selectSort(testArr, SIZE);
   
   // Test
   for (size_t i = 1; i < SIZE; i++)    
      ASSERT_LE(testArr[i-1], testArr[i]);
   
}




//
// -------------- PREDEFINED TESTS ----------------
//

// Test #1
TEST_F(PredefinedArrayTest, bubbleSort_Test) {
  
   // Sort
   bubbleSort(testArr, SIZE);

   // Test
   for (size_t i = 1; i < SIZE; i++)   
      ASSERT_LE(testArr[i-1], testArr[i]);
   
}

// Test #2
TEST_F(PredefinedArrayTest, heapSort_Test) {
  
   // Sort
   heapSort(testArr, SIZE);
   
   // Test
   for (size_t i = 1; i < SIZE; i++)    
      ASSERT_LE(testArr[i-1], testArr[i]);
   
}

// Test #3
TEST_F(PredefinedArrayTest, insertSort_Test) {
  
   // Sort
   insertSort(testArr, SIZE);
   
   // Test
   for (size_t i = 1; i < SIZE; i++)    
      ASSERT_LE(testArr[i-1], testArr[i]);
   
}

// Test #4
TEST_F(PredefinedArrayTest, mergeSort_Test) {
  
   // Sort
   mergeSort(testArr, SIZE);
   
   // Test
   for (size_t i = 1; i < SIZE; i++)    
      ASSERT_LE(testArr[i-1], testArr[i]);
   
}

// Test #5
TEST_F(PredefinedArrayTest, quickSort_Test) {
  
   // Sort
   quickSort(testArr, SIZE);
   
   // Test
   for (size_t i = 1; i < SIZE; i++)    
      ASSERT_LE(testArr[i-1], testArr[i]);
   
}

// Test #6
TEST_F(PredefinedArrayTest, selectSort_Test) {
  
   // Sort
   selectSort(testArr, SIZE);
   
   // Test
   for (size_t i = 1; i < SIZE; i++)    
      ASSERT_LE(testArr[i-1], testArr[i]);
   
}


int main(int argc, char **argv) {
  
    testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
    
}
