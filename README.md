<!-- noashalom5@gmail.com -->

# Container and iterators Project

This project implements a generic container class `MyContainer<T>`, along with multiple custom iterators that allow traversal of the container in various orders (regular, reverse, sorted, and special patterns).

---

## `MyContainer` Class

The `MyContainer` class is a dynamic container that holds elements of any comparable type (such as `int`, `double`, `string`, etc.).  
It supports basic operations like adding, removing, and printing elements, and provides advanced iteration capabilities via custom iterator classes.

### Supported Operations::
Each iterator is defined as a nested class in `MyContainer` and supports standard iteration (`begin()`, `end()`, `operator++`, `operator*`, etc.).

#### Iteration Modes:
1. **Regular Order (`regular_begin`, `regular_end`)**  
   Traverse the elements in the order they were inserted.

2. **Reverse Order (`reverse_begin`, `reverse_end`)**  
   Traverse from last to first.

3. **Ascending Order (`ascending_begin`, `ascending_end`)**  
   Traverse elements from smallest to largest.

4. **Descending Order (`descending_begin`, `descending_end`)**  
   Traverse elements from largest to smallest.

5. **SideCross Order (`sidecross_begin`, `sidecross_end`)**  
   Traverse in this pattern: min, max, 2nd min, 2nd max, ...

6. **MiddleOut Order (`middleout_begin`, `middleout_end`)**  
   Traverse from the middle element, then alternating left and right.

---

## Project Files

- `myContainer.hpp` – Implementation of the `MyContainer` class and iterators
- `main.cpp` – Example usage and demo of all features.
- `test.cpp` – Unit tests using `doctest` for all functionality.

---

## Compile & Run
- `make Main` – Compiles and run the project
- `make test` – Runs the tests (from test.cpp)
- `make valgrind` – Checking memory leaks
- `make clean` – Remove the files from the running

- `make main` – Compile only
- `make test_exe` – Compiles test only
