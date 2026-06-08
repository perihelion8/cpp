#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string& name) {
  name_ = name;
}

Zombie::~Zombie() {
  std::cout << name_ << " is destroyed" << std::endl;
}

void Zombie::announce() {
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
