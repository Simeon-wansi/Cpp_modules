#include "Zombie.hpp"

int main(void)
{
    Zombie zombie1("zombie1");
    zombie1.announce();

    Zombie* foo = newZombie("foo");
    foo->announce();

    randomChump("bar");

    delete foo;

    return (0);
}