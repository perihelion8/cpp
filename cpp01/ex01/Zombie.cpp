#include "Zombie.hpp"
#include <iostream>

void Zombie::set_name(std::string name) { name_ = name; }

Zombie::~Zombie() {
  std::cout << name_ << " is destroyed" << std::endl;
}

void Zombie::announce() {
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
