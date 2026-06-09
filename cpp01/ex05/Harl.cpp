#include "Harl.hpp"
#include <iostream>

const Harl::Action Harl::kActions_[4] = {
  &Harl::debug,
  &Harl::info,
  &Harl::warning,
  &Harl::error
};

const std::string Harl::kLevels_[4] = {
  "DEBUG",
  "INFO",
  "WARNING",
  "ERROR"
};

void Harl::complain(std::string level) {
  for (int i = 0; i < 4; ++i)
    if (level == kLevels_[i]) {
      (this->*kActions_[i])();
      return;
    }
}

void Harl::debug() {
  std::cout << "debug" << std::endl;
}

void Harl::info() {
  std::cout << "info" << std::endl;
}

void Harl::warning() {
  std::cout << "warning" << std::endl;
}

void Harl::error() {
  std::cout << "error" << std::endl;
}
