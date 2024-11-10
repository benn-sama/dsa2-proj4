#include "./offline-bin-problem.hpp"

#include <iostream>

void testOBP() {
  OfflineBasket basket;
  

  std::cout << "\nFirst Fit Offline Bins: " << basket.firstFit();
  std::cout << "\nOnline Values first fit: " << basket.printValues();
  std::cout << "\nBest Fit Offline Bins: " << basket.bestFit();
  std::cout << "\nOnline Values best fit: " << basket.printValues();

}

int main() {
  testOBP();
  return 0;
}