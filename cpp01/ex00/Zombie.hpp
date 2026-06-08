#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
 public:
   Zombie(const std::string& name);
   ~Zombie();

   void announce();

 private:
  std::string name_;

};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif // ZOMBIE_HPP
