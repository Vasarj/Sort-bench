# Sort-bench

## Different sorting algorithms and their benchmarks

The code for sorting algorithms is found in `\inc` directory.
The driver for the set of benchmarks in in `\src` directory.
Algorithms time and memory complexity, along with main key features is found in corresponding headers. See documentation.

Current list of sorting algorithms included:
- Bubble Sort
- Heap Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Selection Sort

Other algorithms can be added to the bench driver easily by inserting the following line in `benchRunner.cpp`
```
algorithms.push_back(make_pair(& /*template sorting function HERE*/ <Type>, "/*name of sorting method HERE*/"));
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
