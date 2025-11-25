#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe& other)
    :_vec(other._vec), _deq(other._deq)
{}

PmergeMe::~PmergeMe() {}


bool PmergeMe::parseInput(int ac , char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" <<std::endl;
        return false;
    }
    //Display "bef"
    std::cout << "Before: ";

    for (int i = 1; i < ac; i++)
    {
        // value has to be positive int
        std::string arg = av[i];

        //checking if all chars are digits 
        for (size_t j = 0; j < arg.length(); j++){
            if (!isdigit(arg[j])) {
                std::cerr <<"Error" << std::endl;
                return false;
            }
        }
        //convert to int
        int num = std::atoi(arg.c_str());

        if (num <= 0){
            std::cerr << "Error" << std::endl;
            return false;
        }

        //print for before: 
        std::cout << num;
        if (i < ac - 1)
            std::cout << " ";

        //storing in both cont
        _vec.push_back(num);
        _deq.push_back(num);
    }

    std::cout << std::endl;
    return true;
}

static double getTime() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000) + time.tv_usec;
}

void PmergeMe::sort() {
    double startVec = getTime();
    _sortVector();
    double endVec =  getTime();
    double vecTime = endVec - startVec;

    double startDeq =  getTime();
    _sortDeque();
    double endDeq = getTime();
    _sortDeque();
    double deqTime = endDeq - startDeq;

    displayResults(vecTime, deqTime);
}


void PmergeMe::displayResults(double vecTime, double deqTime) {

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
    {
        std::cout << _vec[i];
        if (i < _vec.size() -1)
            std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : "
              << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : "
              << deqTime << " us" << std::endl;
}

void PmergeMe::_sortVector() {
    _fordJohnsonVector(_vec);
}

void  PmergeMe::_fordJohnsonVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    size_t i;

    for (i = 0; i + 1 < arr.size(); i += 2)
    {
        int first = arr[i];
        int second = arr[i + 1];

        //larger 1st in pair
        if (first < second)
            pairs.push_back(std::make_pair(second, first));
        else
            pairs.push_back(std::make_pair(first, second));
    }

    //odd elt 
    int straggler = -1;
    bool hasStrangler = false;
    if (i < arr.size())
    {
        straggler =  arr[i];
        hasStrangler =  true;
    }

    // extract larger elts
    std::vector<int> mainChain;
    std::vector<int> pending;

    for (size_t j = 0; j < pairs.size(); j++) {
        mainChain.push_back(pairs[j].first); //larger elt
        pending.push_back(pairs[j].second);
    }

    // recursive sort 
    if (mainChain.size() > 1)
        _fordJohnsonVector(mainChain);

    //insert pending elts using binary search
   
    // for (size_t j = 0; j < pending.size(); j++) {
    //     size_t insertPos = 0;
    //     for (size_t k = 0; k  < mainChain.size(); k++)
    //     {
    //         if (pending[j] < mainChain[k])
    //         {
    //             insertPos = k;
    //             break;
    //         }
    //         insertPos = k + 1;
    //     }
    //     mainChain.insert(mainChain.begin() + insertPos, pending[j]);
    // }
    for (size_t j = 0; j < pending.size(); j++) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[j]);
        mainChain.insert(pos, pending[j]);
    }

    //insert straggler if exist 
    if (hasStrangler){
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    //cpy result back
    arr =  mainChain;
} 

void PmergeMe::_sortDeque() {
    _fordJohnsondeque(_deq);
}

void PmergeMe::_fordJohnsondeque(std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return;
    
    // creations of pairs
    std::vector<std::pair<int, int> > pairs;
    size_t i;

    for (i = 0; i + 1 < arr.size(); i += 2){
        int first =  arr[i];
        int second = arr[i + 1];

        if (first < second)
            pairs.push_back(std::make_pair(second, first));
        else
            pairs.push_back(std::make_pair(first, second));
    }

    // Handle straggler
    int straggler = -1;
    bool hasStraggler = false;

    if (i < arr.size()) {
        straggler = arr[i];
        hasStraggler = true;
    }

    //extract main chain and pending
    std::deque<int> mainChain;
    std::deque<int> pending;


    for (size_t j = 0; j < pairs.size(); j++) {
        mainChain.push_back(pairs[j].first);
        pending.push_back(pairs[j].second);
    }

    // recursive sort
    if (mainChain.size() > 1)
        _fordJohnsondeque(mainChain);
    
    // insert pending
    for (size_t j = 0; j < pending.size(); j++) {
        std::deque<int>::iterator pos =  std::lower_bound(mainChain.begin(), mainChain.end(), pending[j]);
        mainChain.insert(pos, pending[j]);
    }

    //insert strgafler
    if (hasStraggler) {
        std::deque<int>::iterator pos =  std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

