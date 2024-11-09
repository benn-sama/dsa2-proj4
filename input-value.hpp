#ifndef INPUT_VALUE_HPP
#define INPUT_VALUE_HPP

#include <fstream>
#include <sstream>
#include <string>

class Input {
  private:
    std::ifstream fileStream;
  public:
    Input(); // default constructor
    bool openFile(); // opens a file, and returns state of the file
    bool closeFile(); // closes the file, and returns state of the file
    bool isOpen();
    float returnValue(); // returns the next line of the file
};

#endif