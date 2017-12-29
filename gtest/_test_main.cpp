#include <iostream>
#include <memory>    // NEED: unique_ptr

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


class TestEnvironment : public testing::Environment {
  
public:

  static const int SIZE = 30;
  static double* testArr;
  
  static double* generateInputArray( ) {
    
    testArr = new double[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
      testArr[i] = genRandom(-100.0, 100.0);   // FROM: util.h
    }
    
    cout << "Random array of size " << SIZE << " generated.." << endl;
    
    return testArr;
    
  }
  
  virtual void SetUp( ) override {
    
    generateInputArray( );
    cout << "Set up the test environment.." << endl;
    
  }

  virtual void TearDown( ) override {
    
    delete[] testArr;
    cout << "Tear down the test environment.." << endl;
    
  }
  
};


TEST(RandomArrayTest, bubbleSort_Test) {
  
   // Init
   //unique_ptr<double[]> a(new double[TestEnvironment::SIZE]);
   double* a = new double[TestEnvironment::SIZE];
   copyArr(a, TestEnvironment::testArr, TestEnvironment::SIZE);

   // Test
   bubbleSort(a, TestEnvironment::SIZE);

   for (size_t i = 1; i < TestEnvironment::SIZE; i++) {
    
      ASSERT_LE(a[i-1], a[i]);
    
   }
   
   delete[] a;
  
}


int main(int argc, char **argv) {
  
    testing::InitGoogleTest(&argc, argv); 
    testing::AddGlobalTestEnvironment(new TestEnvironment);
    return RUN_ALL_TESTS();
    
}