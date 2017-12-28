/**
*
* @author Alexander Arzhanov
* @version 21/10/17
*
* Bench Runner
* 创创创创创创
*     - Executes benchruns for the listed
*       sorting algorithms. For better accuracy
*       benchruns are repeated 'R' number of times.
*     - Additional algorithms can be added easily,
*       as no extra coding required.
*     - Origin: https://github.com/alar0330/
*
**/



#include <iostream>
#include <chrono>  // NEED: duration, high_resolution_clock
#include <vector>  // NEED: vector
#include <string>  // NEED: string
#include <iomanip> // NEED: setw
#include <utility> // NEED: pair

#include "mergeSort.h"
#include "quickSort.h"
#include "selectSort.h"
#include "heapSort.h"
#include "bubbleSort.h"
#include "insertSort.h"

#include "util.h"

using namespace std;

using std::chrono::duration;
using std::chrono::high_resolution_clock;

int main( ) {

   // --- Size of the array
   const int N = 10 * 1000;

   // --- Type of the array
   using Type = double;

   // --- Number of runs
   const int R = 3;

   // --- Save the results of each run
   vector<vector<double>> res;

   // --- Some declarations / inits
   using Func = void(*) (Type*, const int);
   //
   duration<double> elapsed;
   auto t = high_resolution_clock::now( );
   //
   Type* a = new Type[N];
   Type* b = new Type[N];

   // --- Generate random array
   for (int i = 0; i < N; i++) 
      a[i] = (Type)genRandom(0.0, 100.0);

   // --- Copy generated array for later
   copyArr(b, a, N);

   // --- List of algorithms to test:
   vector<pair<Func, string>> algorithms;
   algorithms.push_back(make_pair(&bubbleSort<Type>, "Bubble Sort"));
   algorithms.push_back(make_pair(&heapSort<Type>,   "Heap Sort"));
   algorithms.push_back(make_pair(&insertSort<Type>, "Insertion Sort"));
   algorithms.push_back(make_pair(&mergeSort<Type>,  "Merge Sort"));
   algorithms.push_back(make_pair(&quickSort<Type>,  "Quick Sort"));
   algorithms.push_back(make_pair(&selectSort<Type>, "Selection Sort"));
   res.resize(algorithms.size( ));

   // --- Display input array
   cout << endl << endl;
   cout << "First 20 items of input array: \n";
   cout << "------------------------------";
   printArray(a, ( N > 20 ? 20 : N));
   cout << "------------------------------";
   cout << endl;

   // --- Benchmark Repetitions
   for (int j = 0; j < R; j++) {

      printf("\n---- Benchrun: %d\n", j + 1);

      int v = 0;

      // --- Benchmark Runs
      for (auto& alg : algorithms) {

         // Copy back from reference
         copyArr(a, b, N);

         // Start timer
         t = high_resolution_clock::now( );

         // Run sorting algoriths
         alg.first(a, N);

         // Measure elapsed time
         elapsed = high_resolution_clock::now( ) - t;

         // Save timer measurement
         res[v++].push_back(elapsed.count( ));

         // Print out time for current run
         cout << "[ " << setw(14) << alg.second << " ] = " << elapsed.count( ) << " sec" << endl;

      }
   }


   // --- Print the average results of all repetitions
   cout << endl << endl << endl;
   cout << "------------------------------------------- \n";
   cout << " RESULTS OF BENCHMARK ( " << N << " items ) \n";
   cout << "------------------------------------------- \n\n";

   // Loop through algorithms
   for (size_t i = 0; i < res.size( ); i++) {

      // Accumulate total time for an algorithm
      double sum = 0.0;
      for (auto& n : res[i]) sum += n;

      // Print the average
      cout << "    [ " << setw(14) << algorithms[i].second << " ] = " << sum / res[i].size() << " sec" << endl;
   }

   cout << endl;
   cout << "----------------( average of " << setw(2) << R << " runs )----- \n";


   // --- Clean up
   delete[] a;
   delete[] b;

}