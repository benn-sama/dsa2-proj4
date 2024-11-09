#include "./input-value.hpp"

#include <iostream>

void testInput() {
  Input input;

  if (!(input.openFile())) {
    std::cout << "File did not open for the first time";
    exit(1);
  }

  while (input.isOpen()) {
    std::cout << input.returnValue() << std::endl;
  }
}

int main() {
  testInput();
}