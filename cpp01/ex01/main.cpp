#include "Zombie.hpp"

int main() {
  const int N = 3;
  Zombie* zombies = zombieHorde(N, "zzz");
  for (int i = 0; i < N; ++i)
    zombies[i].announce();
  delete[] zombies;
  return 0;
}
