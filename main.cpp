/*
 * File: main.cpp
 * Description: This file contains the main function for the bin packing problem.
 *              It initializes the OfflineBasket and OnlineBasket objects, runs
 *              various bin packing algorithms, and prints the results.
 * 
 * Usage: The main function runs first fit, next fit, and best fit algorithms for
 *        both online and offline bin packing. It then prints the number of bins
 *        used by each algorithm and the contents of each bin.
 */

#include "offline-bin-problem.hpp"
#include "online-bin-problem.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

int main() {
  OfflineBasket offlineBasket;
  OnlineBasket onlineBasket;
  int minOnlineBins = 13;
  int minOfflineBins = 13;
  int trueMin = 0;

  std::cout << "Working..." << std::endl << std::endl;
  std::vector<int> offlineBins;
  offlineBins.push_back(offlineBasket.firstFit());
  std::string offlineFirstFit = offlineBasket.printValues();
  offlineBins.push_back(offlineBasket.bestFit());
  std::string offlineBestFit = offlineBasket.printValues();

  for (int i = 0; i < int(offlineBins.size()); ++i) {
    if (offlineBins[i] < minOfflineBins) {
      minOfflineBins = offlineBins[i];
    }
  }

  std::vector<int> onlineBins;
  onlineBins.push_back(onlineBasket.firstFit());
  std::string onlineFirstFitValues = onlineBasket.printAll();
  onlineBins.push_back(onlineBasket.nextFit());
  std::string onlineNextFitValues = onlineBasket.printAll();
  onlineBins.push_back(onlineBasket.bestFit());
  std::string onlineBestFitValues = onlineBasket.printAll();

  for (int i = 0; i < int(onlineBins.size()); ++i) {
    if (onlineBins[i] < minOnlineBins) {
      minOnlineBins = onlineBins[i];
    }
  }

  if (minOnlineBins < minOfflineBins) {
    trueMin = minOfflineBins;
  } 
  else {
    trueMin = minOnlineBins;
  }

  std::cout << "  Policy          | Total Bins |" << std::endl;
  std::cout << "Online Algorithm  | " << std::setw(12) << "|" << std::endl;
  std::cout << "First Fit         | " << onlineBins[0] << std::setw(11) << "|" << std::endl;
  std::cout << "Next Fit          | " << onlineBins[1] << std::setw(11) << "|" << std::endl;
  std::cout << "Best Fit          | " << onlineBins[2] << std::setw(11) << "|" << std::endl;
  std::cout << "Offline Algorithm | " << std::setw(12) << "|" << std::endl;
  std::cout << "First Fit         | " << offlineBins[0] << std::setw(11) << "|" << std::endl;
  std::cout << "Best Fit          | " << offlineBins[1] << std::setw(11) << "|" << std::endl;
  std::cout << "Optimal Bins    | " << trueMin << std::setw(11) << "|" << std::endl;

  std::cout << std::endl;
  std::cout << "Online First Fit Values: " << std::endl << onlineFirstFitValues << std::endl;
  std::cout << "Online Next Fit Values: " << std::endl << onlineNextFitValues << std::endl;
  std::cout << "Online Best Fit Values: " << std::endl << onlineBestFitValues << std::endl;
  std::cout << "Offline First Fit Values: " << std::endl << offlineFirstFit << std::endl;
  std::cout << "Offline Best Fit Values: " << std::endl << offlineBestFit << std::endl;

  return 0;
}