#ifndef ONLINE_BIN_PROBLEM_HPP
#define ONLINE_BIN_PROBLEM_HPP

#include "input-value.hpp"
#include "bin.hpp"

#include <vector>

class OnlineBasket {
  private:
    std::vector<Bin*> bins;
    Input* input;
    int binCount;
  public:
    OnlineBasket();
    int firstFit();
    int nextFit();
    int bestFit();
    void addBin();
    void clearBins();
    ~OnlineBasket();
};

#endif