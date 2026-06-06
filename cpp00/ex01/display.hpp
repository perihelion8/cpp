#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>

namespace display {

  void DisplayRow(const std::string row[]);
  void DisplayBox(const std::string& str);
  std::string ReadInput(const std::string & str);
  std::string ReadName(const std::string& name_type);
  std::string ReadPhonenumber();
  std::string ReadDarkSecret();

}

#endif
