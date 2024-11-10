#include "./offline-bin-problem.hpp"

#include <iostream>

void testOBP() {
  OfflineBasket basket;
  

  std::cout << "\nFirst Fit Offline Bins: " << basket.firstFit();

}

int main() {
  testOBP();
  return 0;
}