#ifndef OFFLINE_BIN_PROBLEM_HPP
#define OFFLINE_BIN_PROBLEM_HPP

#include "input-value.hpp"
#include "bin.hpp"

#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class OfflineBasket {
  private: 
    std::vector<float> values;
    std::vector<Bin*> bins;
    int binCount;
    int optimizedBinNum;
    Input* input;
    bool permComplete;
  public:
    OfflineBasket(); // default constructor
    void perm1(); // permutation algorithm
    int firstFit(); // first fit heuristic 
    int bestFit();  // best fit heuristic
    void addBin();  // adds new bin to the bins vector
    void clearBins(bool input); // deletes all elements from bins
    void checkMinBin(); // checks if the binCount is less than optimizedBinNum
    void clearValues(); // clears all elements from values vector
    void fillValues();  // fills values into values vector
    ~OfflineBasket(); // destructor
};

#endif