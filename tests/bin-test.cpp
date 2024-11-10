#include "./bin.hpp"

#include <iostream>

void binTest() {
  Bin bin;

  bin.insert(0.3);
  std::cout << bin.returnBinSize() << std::endl;

  bin.insert(0.5);
  std::cout << bin.returnBinSize() << std::endl;

  bin.insert(0.2);
  std::cout << bin.returnBinSize() << std::endl;

  std::cout << "nodes: " << std::endl;
  std::cout << bin.printAll() << std::endl;
}

int main() {
  binTest();

  return 0;
}