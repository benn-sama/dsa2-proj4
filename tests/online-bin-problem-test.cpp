#include "online-bin-problem.hpp"

#include <iostream>

void opTest() {
  Basket basket;

  std::cout << "Total Next Fit Bins: " << basket.nextFit() << std::endl;
  std::cout << "Total First Fit Bins: " << basket.firstFit() << std::endl;
}

int main() {
  opTest();
}