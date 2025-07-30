#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    _name = name;
}

Zombie::~Zombie(void) {
    std::cout << _name << " is dead" << std::endl;
}

void Zombie::announce(void) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        horde[i] = Zombie(name);
    }
    return (horde);
}