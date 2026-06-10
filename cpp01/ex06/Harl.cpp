#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
  levels_[0] = "DEBUG";
  levels_[1] = "INFO";
  levels_[2] = "WARNING";
  levels_[3] = "ERROR";
}

void Harl::complain(std::string str) {
  int i = 0;

  while (i < kUNKOWN && str != levels_[i])
    i++;
  
  switch (i) {
    case kDEBUG:
      debug();
    case kINFO:
      info();
    case kWARNING:
      warning();
    case kERROR:
      error();
      break;
    default: {
      std::cout << "Invalid level: " << str << std::endl;
      break;
    }
  }
}

void Harl::debug() {
  std::cout
    << "[ DEBUG ]\n"
    << "I love having extra bacon for my"
    << " 7XL-double-cheese-triple-pickle-special-"
    << "ketchup burger. I really do!"
    << std::endl;
}

void Harl::info() {
  std::cout
    << "[ INFO ]\n"
    << "I cannot believe adding extra bacon costs more money."
    << " You didn’t put enough bacon in my burger!"
    << " If you did, I wouldn’t be asking for more!"
    << std::endl;
}

void Harl::warning() {
  std::cout
    << "[ WARNING ]\n"
    << "I think I deserve to have some extra bacon for free."
    << " I’ve been coming for"
    << " years, whereas you started working here just last month."
    << std::endl;
}

void Harl::error() {
  std::cout
    << "[ ERROR ]\n"
    << "This is unacceptable!"
    << " I want to speak to the manager now."
    << std::endl;
}
