#include "online-bin-problem.hpp"

Basket::Basket() {
  input = new Input();
}

int Basket::firstFit() {
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

int Basket::nextFit() {
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

int Basket::bestFit() {
  this->clearBins();

  while (input->isOpen()) {
    bool fitted = false;
    int index = 0;
    float min = 2.0;

    for (int i = 0; i < binCount; ++i) {

    }
  }
  return 0;
}

void Basket::addBin() {
  bins.push_back(new Bin);
  ++binCount;
}

// clears bins
void Basket::clearBins() {
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

// destructor for input
Basket::~Basket() {
  delete input;
}