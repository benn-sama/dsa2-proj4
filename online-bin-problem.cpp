#include "online-bin-problem.hpp"

OnlineBasket::OnlineBasket() {
  input = new Input();
}

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

int OnlineBasket::bestFit() {
  this->clearBins();
  float value = input->returnValue();

  while (input->isOpen()) {
    bool fitted = false;
    int index = 0;
    float min = 2.0;
    
    for (int i = 0; i < binCount; ++i) {
      if (bins[i]->returnBinSize() + value < 1.0 && bins[i]->returnBinSize() + value < min) {
        index = i;
        min = bins[i]->returnBinSize() + value;
        fitted = true;
      }
    }

    if (!fitted) {
      this->addBin();
      bins[binCount - 1]->insert(value);
    }

    bins[index]->insert(value);
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

// destructor for input
OnlineBasket::~OnlineBasket() {
  delete input;
}