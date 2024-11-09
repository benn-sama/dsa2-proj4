#include "bin.hpp"

// default constructor
Bin::Bin() {
  size = 0;
}

// inserts value in the bin
void Bin::insert(float value) {
  size += value;

  if (size == 0) {
    minHeap.push_back(new float(value));
    return;
  }

  this->percolateUp(value);
}

// algorithm when adding a new value
void Bin::percolateUp(float value) {
    // add new element to the end of the heap
    int slot = minHeap.size();
    minHeap.push_back(new float(value));
    
    // while we haven't reached the root and the parent is larger than the new value
    while (slot > 0 && value < *minHeap[(slot - 1) / 2]) {
        // copy the parent down
        *minHeap[slot] = *minHeap[(slot - 1) / 2];
        // move up to the parent's position
        slot = (slot - 1) / 2;
    }
    
    // place the new value in its final position
    *minHeap[slot] = value;
}

// returns bin size
float Bin::returnBinSize() {
  return size;
}

// prints all the nodes
void Bin::printAll() {
  for (int i = 0; i < int(minHeap.size()); ++i) {
    std::cout << *minHeap[i] << std::endl;
  }
}

// clears bin
void Bin::emptyBin() {
  minHeap.clear();
}