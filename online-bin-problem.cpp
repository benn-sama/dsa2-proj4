#include "online-bin-problem.hpp"

// default constructor
OnlineBasket::OnlineBasket() {
  input = new Input();
}

// first fit algorithm
int OnlineBasket::firstFit() {
  this->clearBins();
  float value = input->returnValue();

  while (input->isOpen()) {
    bool fitted = false;

    for (int i = 0; i < binCount; ++i) {
      if (bins[i]->returnBinSize() + value <= 1.0) {
        bins[i]->insert(value);
        fitted = true;
        break;
      }
    }

    if (!fitted) {
      this->addBin();
      bins[binCount - 1]->insert(value);
    }

    value = input->returnValue();
  }

  return binCount;
}

// next fit algorithm
int OnlineBasket::nextFit() {
  this->clearBins();
  float value = input->returnValue();

  // algorithm for next fit 
  while (input->isOpen()) {
    if (bins[binCount - 1]->returnBinSize() + value > 1.0) {
      this->addBin();
    }

    bins[binCount - 1]->insert(value);
    value = input->returnValue();
  }

  return binCount;
}

// best fit algorithm
int OnlineBasket::bestFit() {
  this->clearBins();
  float value = input->returnValue();
  
  while (input->isOpen()) {
    bool fitted = false;
    int index = 0;
    float min = 2.0;

    //find best fitting bin
    for (int i = 0; i < binCount; ++i) {
      if (bins[i]->returnBinSize() + value <= 1.0) {  
        float remaining = 1.0 - (bins[i]->returnBinSize() + value);
        if (remaining < min) {
          min = remaining;
          index = i;
          fitted = true;
        }
      }
    }

    // insert value in either existing or new bin
    if (!fitted) {
      this->addBin();
      bins[binCount - 1]->insert(value);
    } 
    else {
      bins[index]->insert(value);
    }

    value = input->returnValue();
  }

  return binCount;
}

void OnlineBasket::addBin() {
  bins.push_back(new Bin);
  ++binCount;
}

// clears bins
void OnlineBasket::clearBins() {
  // delete all existing bins
  for (int i = 0; i < binCount; ++i) {
    bins[i]->emptyBin();
    delete bins[i];
  }
  bins.clear();
    
  delete input;
  input = new Input;
  input->openFile();
  // start with one empty bin
  bins.push_back(new Bin());
  binCount = 1;
}

// prints all values
std::string OnlineBasket::printAll() {
  std::string bucket = "";

  for (int i = 0; i < binCount; ++i) {
    bucket += "b" + std::to_string(i) + ": " + bins[i]->printAll() + "\n";
  }

  return bucket;
}

// destructor for input
OnlineBasket::~OnlineBasket() {
  delete input;
}