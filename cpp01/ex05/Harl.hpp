#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
 public:
  void complain(std::string level);

 private:
  typedef void (Harl::*Action)();

  static const std::string kLevels_[4];
  static const Harl::Action kActions_[4];

  void debug();
  void info();
  void warning();
  void error();
};

#endif // HARL_HPP
