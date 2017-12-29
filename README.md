# Sort-bench

## Different sorting algorithms and their benchmarks

This mini-project offers a naive implementation of a few popular sorting algorithms for the sake of practice. The provided benchmarking driver is to quantitatively evaluate their performance.

The code for sorting algorithms is found in `\inc` directory.
The driver for the set of benchmarks is in `\src` directory.
Algorithms time and memory complexity, along with discussion of some key features, are found in corresponding headers. See documentation.

Googletest unit tests are included in `\gtest` to validate the sorting algorithms. **Compile & test** with `make test`.

Current list of sorting algorithms include:
- Bubble Sort
- Heap Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Selection Sort

Other algorithms can be added to the bench driver easily by inserting the following line into `benchRunner.cpp`
```C++
algorithms.push_back(make_pair(& /*template of sorting METHOD*/ <Type>, "/*sorting method NAME*/"));
```

## Compile & Run
```
make run
```

## Sample output
```
-------------------------------------------
 RESULTS OF BENCHMARK ( 50000 items )
-------------------------------------------

    [      Heap Sort ] = 0.0140328 sec
    [ Insertion Sort ] = 1.23837 sec
    [     Merge Sort ] = 0.0202466 sec
    [     Quick Sort ] = 0.00782 sec
    [    Bubble Sort ] = 8.40487 sec
    [ Selection Sort ] = 7.81709 sec

----------------( average of  5 runs )-----
```
