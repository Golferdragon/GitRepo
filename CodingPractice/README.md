# Coding Practice

This folder contains small C and C++ programs used to practice programming fundamentals, algorithms, data structures, and problem-solving techniques.

The goal of this section is to show continued hands-on practice with lower-level programming concepts that are useful for embedded software and systems work.

## Folder Structure

| Folder | Description |
|---|---|
| `C/` | C language practice programs |
| `Cpp/` | C++ practice programs |

## Programs

| File | Language | Concept |
|---|---:|---|
| `CircularBuffer.c` | C | Circular buffer implementation, buffer state tracking, wraparound logic |
| `ipStringDedupe.cpp` | C++ | String/data cleanup practice |
| `palindromeNumberIntegerSolution.cpp` | C++ | Numeric palindrome logic without relying primarily on string conversion |
| `palindromeNumberSolution.cpp` | C++ | Palindrome checking practice |
| `reverseLinkedList.cpp` | C++ | Linked list pointer manipulation |
| `romanToInteger.cpp` | C++ | String parsing and conditional logic |
| `romanToIntegerLookupTable.cpp` | C++ | Lookup table optimization |
| `twoSum.cpp` | C++ | Brute-force array search |
| `twoSumHashMapSolution.cpp` | C++ | Hash map based optimization |

## Build Notes

These programs are intended to be built individually rather than as one combined project.

Example C build:

```bash
gcc C/CircularBuffer.c -o CircularBuffer.exe
g++ Cpp/twoSumHashMapSolution.cpp -o twoSumHashMapSolution.exe
