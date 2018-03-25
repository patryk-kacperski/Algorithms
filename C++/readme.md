## Algorithms implemented in C++

### General info

Each directory contains:
- **algorithm.h** - Header file containing declaration of functions and classes or their implementations if they are templates
- **algorithm.cpp** - Implementation of non-template functions
- **Test** - Directory with tests for an algorithm. It contains:
  - **main.cpp** - File that runs tests. 
  - **test.h** - Declaration of test functions.
  - **test.cpp** - Implementation of test functions. Each function returns boolean value (test either passes or not). In main.cpp these values are checked with assert function.
  
Most files will require `std=c++11` to be compiled

### Table of contents

- **Binsearch** - Contains iterative binary search algorithm,
- **Matrix** - Contains class being implementation of a Matrix. It has overloaded << >> + - * operators. Multiplication is performed with recurrent Strassen algorithm,
- **Mergesort** - Contains recurrent merge sort algorithm,
- **Quicksort** - Contains recurrent quick sort algorithm
