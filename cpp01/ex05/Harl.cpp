#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
  levels_[0] = "DEBUG";
  levels_[1] = "INFO";
  levels_[2] = "WARNING";
  levels_[3] = "ERROR";

  actions_[0] = &Harl::debug;
  actions_[1] = &Harl::info;
  actions_[2] = &Harl::warning;
  actions_[3] = &Harl::error;
}

void Harl::complain(std::string level) {
  for (int i = 0; i < 4; ++i)
    if (level == levels_[i]) {
      (this->*actions_[i])();
      return;
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
