#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
 public:
   void set_name(std::string name);
   ~Zombie();

   void announce();

 private:
  std::string name_;

};

Zombie* zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP
