#include "online-bin-problem.hpp"

#include <iostream>

void opTest() {
  OnlineBasket basket;

  std::cout << "Total Next Fit Bins: " << basket.nextFit() << std::endl;
  std::cout << "Values Next Fit: " << basket.printAll() << std::endl;
  std::cout << "Total First Fit Bins: " << basket.firstFit() << std::endl;
  std::cout << "values First Fit: " << basket.printAll() << std::endl;
  std::cout << "Total Best Fit Bins: " << basket.bestFit() << std::endl;
  std::cout << "values First Fit: " << basket.printAll() << std::endl;
}

int main() {
  opTest();
}