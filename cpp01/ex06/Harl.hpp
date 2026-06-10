#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
 public:
  enum Level {
    kDEBUG = 0,
    kINFO,
    kWARNING,
    kERROR,
    kUNKOWN
  };

  Harl();
  void complain(std::string level);

 private:
  void debug();
  void info();
  void warning();
  void error();

  std::string levels_[4];
};

#endif // HARL_HPP
