/*
 * File: input-value.hpp, input-value.cpp
 * Description: This header file defines the Input class, which handles file operations
 *              for reading floating point values from a file. It provides methods to
 *              open, close, and read values from the file.
 * 
 * Usage: The Input class provides methods to open a file, check if it is open, read the
 *        next value from the file, and close the file. It is used to read input values
 *        for bin packing algorithms.
 */

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