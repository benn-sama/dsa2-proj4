#include "input-value.hpp"

// default constructor
Input::Input() {}

// opens file, and returns state of the file
bool Input::openFile() {
  fileStream.open("./items.txt");
  return fileStream.is_open();
}

// closes file, and returns state of the file
bool Input::closeFile() {
  fileStream.close();
  return !fileStream.is_open();
}

// checks if file is still open
bool Input::isOpen() {
  return fileStream.is_open();
}

// returns values from the file
float Input::returnValue() {
  float value;

  // makes sure the file is still open
  if (!this->isOpen()) {
    return -2.0;
  }
  
  // tokenizes the value
  fileStream >> value;

  // makes sure file's next token isn't the end
  if (fileStream.peek() == EOF) {
    this->closeFile();
    return -1.0;
  }


  // only allows values less then one
  while (value > 1) {
    if (fileStream.peek() == EOF) {
      return -1.0;
    }

    fileStream >> value;
  }

  return value;
}