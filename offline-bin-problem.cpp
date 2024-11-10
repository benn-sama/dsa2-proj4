#include "offline-bin-problem.hpp"

// default constructor
OfflineBasket::OfflineBasket() {
  input = new Input;
}

// permutation algorithm
void OfflineBasket::perm1() {
  int m, k, p, q;

  m = int(values.size()) - 2;
  while (values[m] > values[m + 1]) {
    m = m - 1;
  }

  // added this to check if more permutations are available
  if (m < 0) {
    permComplete = true;
    return;
  }

  k = int(values.size()) - 1;
  while (values[m] > values[k]) {
    k = k - 1;
  }

  std::swap(values[m], values[k]);
  p = m + 1;
  q = int(values.size()) - 1;
  while (p < q) {
    std::swap(values[p], values[q]);
    ++p;
    --q;
  }
}

// first fit algorithm
int OfflineBasket::firstFit() {
    this->clearBins(true);
    this->fillValues();
    optimizedBinNum = int(values.size());  // start with worst case
    permComplete = false;

    while (!permComplete) {
        this->clearBins(false);
        
        // process each value in current permutation
        for (float value : values) {
            bool fitted = false;
            
            // try existing bins first
            for (int j = 0; j < binCount; ++j) {
                if (bins[j]->returnBinSize() + value <= 1.0) {
                    bins[j]->insert(value);
                    fitted = true;
                    break;
                }
            }
            
            // create new bin if needed
            if (!fitted) {
                this->addBin();
                bins[binCount - 1]->insert(value);
            }
        }
        
        this->checkMinBin();
        this->perm1();
    }

    return optimizedBinNum;
}

// best fit algorithm
int OfflineBasket::bestFit() {
  return 0;
}

// adds new bin
void OfflineBasket::addBin() {
  bins.push_back(new Bin);
  ++binCount;
}

// clears bins
// parameter is true, allocate  nput
// if false, don't allocate new input
void OfflineBasket::clearBins(bool reinitInput) {
    // Delete all existing bins
    for (int i = 0; i < int(bins.size()); ++i) {
        bins[i]->emptyBin();
        delete bins[i];
    }
    bins.clear();

    // checks if we need to use another input again
    if (reinitInput) {
        delete input;
        input = new Input;
        input->openFile();
    }

    // Start with one empty bin
    bins.push_back(new Bin());
    binCount = 1;
}

// checks for new min bin count
void OfflineBasket::checkMinBin() {
  if (binCount < optimizedBinNum) {
    optimizedBinNum = binCount;
  }
}

// clears and returns true if successfull
// returns false if already cleared
void OfflineBasket::clearValues() {
  if (int(values.size()) > 0) {
    values.clear();
  }
}

void OfflineBasket::fillValues() {
    this->clearValues();

    while (input->isOpen()) {
        float value = input->returnValue();
        if (value > 0.0) {
            values.push_back(value);
        }
    }
    
    // Sort initially - this ensures we start with the first permutation
    std::sort(values.begin(), values.end());
}

// deconstructor
OfflineBasket::~OfflineBasket() {
  delete input;
}