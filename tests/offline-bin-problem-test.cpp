#include "./offline-bin-problem.hpp"

#include <iostream>

void testOBP() {
  OfflineBasket basket;
  

  std::cout << "\nFirst Fit Offline Bins: " << basket.firstFit();
  std::cout << "\nBest Fit Offline Bins: " << basket.bestFit();

}

int main() {
  testOBP();
  return 0;
}