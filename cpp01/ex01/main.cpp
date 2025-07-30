#include "Zombie.hpp"

int main(void)
{
    Zombie* zombie = zombieHorde(10, "zombie");
    for (int i = 0; i < 10; i++)
        zombie[i].announce();
    delete[] zombie;
    return (0);
}