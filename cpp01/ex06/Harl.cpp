#include "Harl.hpp"
#include <iostream>

void Harl::complain(std::string level) {
}

void Harl::debug() {
  std::cout
    << " love having extra bacon for my "
    << "7XL-double-cheese-triple-pickle-special-"
    << "ketchup burger. I really do!"
    << std::endl;
}

void Harl::info() {
  std::cout
    << "I cannot believe adding extra bacon costs more money."
    << " You didn’t put enough bacon in my burger! "
    << "If you did, I wouldn’t be asking for more!"
    << std::endl;
}

void Harl::warning() {
  std::cout << "warning" << std::endl;
}

void Harl::error() {
  std::cout << "error" << std::endl;
}
