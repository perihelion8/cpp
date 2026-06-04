#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

namespace display {

  void DisplayRow(const std::string row[]);
  void DisplayBox(const std::string& str);
  std::string PromptForField(const std::string & str);
  
}

#endif
