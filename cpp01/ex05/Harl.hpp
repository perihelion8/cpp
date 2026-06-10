#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
 public:
  Harl();
  void complain(std::string level);

 private:
  typedef void (Harl::*Action)();

  void debug();
  void info();
  void warning();
  void error();

  std::string levels_[4];
  Harl::Action actions_[4];
};

#endif // HARL_HPP
