#include "display.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include "validate.hpp"

namespace display {

  std::string TruncateString(std::string str) {
    return str.length() <= 10 ? str : str.substr(0, 9) + ".";
  }

  void DisplayRow(const std::string row[]) {
    for (int i = 0; i < 4; ++i) {
      std::cout << std::right << std::setw(10) << TruncateString(row[i]);
      if (i < 3) std::cout << '|';
    }
    std::cout << std::endl;
  }

  void DisplayBox(const std::string& str) {
    std::string line = "-----------------------";
    std::cout << line << std::endl << str << std::endl << line << std::endl;
  }

  std::string ReadInput(const std::string& field) {
    std::string value = "";
    while (IsNotEmpty(value)) {
      std::cout << field << ": ";
      std::getline(std::cin, value); 
    }
    return value;
  }

}
