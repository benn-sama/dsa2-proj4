#ifndef ONLINE_BIN_PROBLEM_HPP
#define ONLINE_BIN_PROBLEM_HPP

#include "input-value.hpp"
#include "bin.hpp"

#include <vector>

class Basket {
  private:
    std::vector<Bin*> bins;
    Input* input;
    int binCount;
  public:
    Basket();
    int firstFit();
    int nextFit();
    int bestFit();
    void addBin();
    void clearBins();
    ~Basket();
};

#endif