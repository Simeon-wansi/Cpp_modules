#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    PmergeMe pmm;

    if (!pmm.parseInput(ac, av))
        return 1;

    pmm.sort();

    return 0;
}