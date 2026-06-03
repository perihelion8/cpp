#include "display.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

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
    std::vector<std::string> lines;
    std::istringstream iss(str);
    std::string line;
    while (std::getline(iss, line)) lines.push_back(line);
    if (lines.empty()) lines.push_back("");

    std::size_t maxlen = 0;
    for (std::size_t i = 0; i < lines.size(); ++i)
      if (lines[i].length() > maxlen) maxlen = lines[i].length();

    const std::size_t padding = 2;
    std::string border = "+" + std::string(maxlen + padding * 2, '-') + "+";

    std::cout << border << std::endl;
    for (std::size_t i = 0; i < lines.size(); ++i) {
      std::string s = lines[i];
      std::size_t right = maxlen - s.length();
      std::cout << "|" << std::string(padding, ' ') << s << std::string(right + padding, ' ') << "|" << std::endl;
    }
    std::cout << border << std::endl;
  }

}
