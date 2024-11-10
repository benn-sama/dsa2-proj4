/*
 * File: bin.hpp bin.cpp
 * Description: This header file defines the Bin class, which implements a min heap
 *              data structure for storing floating point values between 0 and 1.
 *              Each bin has a maximum capacity of 1.0 and maintains items in sorted order.
 * 
 * Usage: The Bin class provides methods to insert values, maintain heap property,
 *        track bin fullness, and display contents. It is used as a container for both
 *        online and offline bin packing algorithms.
 */

#ifndef BIN_HPP
#define BIN_HPP


#include <vector>
#include <string>
#include <iostream>

class Bin {
  private:
    std::vector<float*> minHeap;
    float size;
  public:
    Bin(); // default constructor
    void insert(float value); // inserts new value into the heap
    void percolateUp(float value); // maintains min heap
    float returnBinSize(); // returns the bin size
    void emptyBin(); // emptys bin
    std::string printAll();
};

#endif