#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>

class PmergeMe{

private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    //hlpers
    void _sortVector();
    void _sortDeque();

    void _fordJohnsonVector(std::vector<int>& arr);
    void _fordJohnsondeque(std::deque<int>& arr);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    bool parseInput(int ac, char** av);
    void sort();
    void displayResults(double vecTime, double deqTime);

};


#endif