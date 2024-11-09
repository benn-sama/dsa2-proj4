#ifndef BIN
#define BIN_HPP


#include <vector>
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
    void printAll();
};

#endif