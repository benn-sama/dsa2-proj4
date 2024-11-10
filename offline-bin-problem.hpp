/*
 * File: offline-bin-problem.hpp, offline-bin-problem.cpp
 * Description: This header file defines the OfflineBasket class, which implements
 *              offline bin packing algorithms using first fit and best fit heuristics.
 * 
 * Usage: The OfflineBasket class provides methods to initialize the bin packing problem,
 *        apply permutation algorithms, and execute first fit and best fit heuristics.
 *        It also includes methods to manage bins, check for optimized bin count, and
 *        print the values in the bins.
 */

#ifndef OFFLINE_BIN_PROBLEM_HPP
#define OFFLINE_BIN_PROBLEM_HPP

#include "input-value.hpp"
#include "bin.hpp"

#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

class OfflineBasket {
  private: 
    std::vector<float> values;
    std::vector<Bin*> bins;
    int binCount;
    int optimizedBinNum;
    Input* input;
    bool permComplete;
    int count = 0;
    std::string valuesPrinted = "";
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
    std::string printValues();
    ~OfflineBasket(); // destructor
};

#endif