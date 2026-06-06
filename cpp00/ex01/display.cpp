#include "display.hpp"
#include <iostream>
#include <iomanip>
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
    while (!validate::IsNotEmpty(value)) {
      std::cout << field << ": ";
      std::getline(std::cin, value); 
    }
    return value;
  }

  std::string ReadName(const std::string& field_name) {
    std::string input = ReadInput(field_name);
    while (!validate::IsValidName(input)) {
      std::cout << "\nName must not exceed 20 characters, and may only contain alphabetic characters.\n" << std::endl;
      input = ReadInput(field_name);
    }
    return input;
  }

  std::string ReadPhonenumber() {
    std::string input = ReadInput("phonenumber");
    while (!validate::IsValidPhonenumber(input)) {
      std::cout << "\nInsert a valid phonenumber.\n" << std::endl;
      input = ReadInput("phonenumber");
    }
    return input;
  }

  std::string ReadDarkSecret() {
    std::string input = ReadInput("dark secret");
    while (!validate::IsValidDarkSecret(input)) {
      std::cout << "\nDark secret must not exceed 100 characters\n" << std::endl;
      input = ReadInput("dark secret");
    }
    return input;
  }

}
