/*
 * File: online-bin-problem.hpp, online-bin-problem.cpp
 * Description: This header file defines the OnlineBasket class, which implements
 *              online bin packing algorithms using first fit, next fit, and best fit heuristics.
 * 
 * Usage: The OnlineBasket class provides methods to initialize the bin packing problem,
 *        execute first fit, next fit, and best fit heuristics, manage bins, and print
 *        the values in the bins.
 */

#ifndef ONLINE_BIN_PROBLEM_HPP
#define ONLINE_BIN_PROBLEM_HPP

#include "input-value.hpp"
#include "bin.hpp"

#include <vector>
#include <string>

class OnlineBasket {
  private:
    std::vector<Bin*> bins;
    Input* input;
    int binCount;
  public:
    OnlineBasket(); // default constructor
    int firstFit(); // first fit algorithm
    int nextFit(); // next fit algorithm
    int bestFit(); // best fit algorithm
    void addBin(); // adds new bin
    void clearBins(); // clears bins
    std::string printAll(); // prints all values
    ~OnlineBasket(); // destructor
};

#endif