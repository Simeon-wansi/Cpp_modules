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
    return (time.tv_sec * 1000000.0) + (double)time.tv_usec;
}

void PmergeMe::sort() {

    double startVec = getTime();
    _sortVector();
    double endVec =  getTime();
    double vecTime = endVec - startVec;

    double startDeq =  getTime();
    _sortDeque();
    double endDeq = getTime();
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
              << std::fixed << std::setprecision(5)
              << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : "
              << std::fixed << std::setprecision(5)
              << deqTime << " us" << std::endl;
}


std::vector<size_t> PmergeMe::_generateJacobsthalVector(size_t n)
{
    // Jo = 2 , J1 = 1
    //  Jn = J(n-1) + 2J(n-2)
    std::vector<size_t> jacobsthal;

    if (n == 0)
        return jacobsthal;

    jacobsthal.push_back(0);
    if (n == 1)
        return jacobsthal;
    
    jacobsthal.push_back(1);

    // generate sequence untill we exceed n
    size_t prev2 = 0; // J(n-2)
    size_t prev1 = 1; // J(n-1)

    while(true)
    {
        size_t next = prev1 + 2 * prev2;
        if (next > n)
            break;
        jacobsthal.push_back(next);
        prev2 = prev1;
        prev1 = next;
    }
    return jacobsthal; 
}


std::vector<size_t> PmergeMe::_generateInsertionOrderVector(size_t pendingSize)
{
    std::vector<size_t> order;

    if (pendingSize == 0)
        return order;
    
    //generate Jacobsthal nums to the pensingsize
    std::vector<size_t> jacob = _generateJacobsthalVector(pendingSize);

    //Build insertion order
    for (size_t i = 2; i < jacob.size(); i++){
        size_t current =  jacob[i];
        size_t previous = jacob[i - 1];

        //add cur jacobsthal num
        if (current < pendingSize)
            order.push_back(current);
        //add all nums bet8n previous and curr (descding)
        for (size_t j = current - 1; j > previous; j--) {
            if (j < pendingSize)
                order.push_back(j);
        }
    }
    //addin any remaining elts not covered
    for (size_t i =  jacob.back() + 1; i < pendingSize; i++) {
        order.push_back(i);
    }
    return order;
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
    bool hasStraggler = false;
    if (i < arr.size())
    {
        straggler =  arr[i];
        hasStraggler =  true;
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
    //special case
    if (pending.size() > 0) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[0]);
        mainChain.insert(pos, pending[0]);
    }
    //inserting the remaining

    if (pending.size() > 1)
    {
        std::vector<size_t> insertOrder = _generateInsertionOrderVector(pending.size());

        for (size_t j = 0; j < insertOrder.size(); j++) {
            size_t idx =  insertOrder[j];

            //skipping index 0
            if (idx == 0)
                continue;
            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[idx]);
            mainChain.insert(pos, pending[idx]);
        }
    }
    //insert straggler if exist 
    if (hasStraggler){
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    //cpy result back
    arr =  mainChain;
} 

// == deque ==

std::deque<size_t> PmergeMe::_generateJacobsthalDeque(size_t n)
{
    // Jo = 2 , J1 = 1
    //  Jn = J(n-1) + 2J(n-2)
    std::deque<size_t> jacobsthal;

    if (n == 0)
        return jacobsthal;

    jacobsthal.push_back(0);
    if (n == 1)
        return jacobsthal;
    
    jacobsthal.push_back(1);

    // generate sequence untill we exceed n
    size_t prev2 = 0; // J(n-2)
    size_t prev1 = 1; // J(n-1)

    while(true)
    {
        size_t next = prev1 + 2 * prev2;
        if (next > n)
            break;
        jacobsthal.push_back(next);
        prev2 = prev1;
        prev1 = next;
    }
    return jacobsthal; 
}


std::deque<size_t> PmergeMe::_generateInsertionOrderDeque(size_t pendingSize)
{
    std::deque<size_t> order;

    if (pendingSize == 0)
        return order;
    
    //generate Jacobsthal nums to the pensingsize
    std::deque<size_t> jacob = _generateJacobsthalDeque(pendingSize);

    //Build insertion order
    for (size_t i = 2; i < jacob.size(); i++){
        size_t current =  jacob[i];
        size_t previous = jacob[i - 1];

        //add cur jacobsthal num
        if (current < pendingSize)
            order.push_back(current);
        //add all nums bet8n previous and curr (descding)
        for (size_t j = current - 1; j > previous; j--) {
            if (j < pendingSize)
                order.push_back(j);
        }
    }
    //addin any remaining elts not covered
    for (size_t i =  jacob.back() + 1; i < pendingSize; i++) {
        order.push_back(i);
    }
    return order;
}


void PmergeMe::_sortDeque() {
    _fordJohnsonDeque(_deq);
}

void PmergeMe::_fordJohnsonDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1)
        return;
    
    // creations of pairs
    std::deque<std::pair<int, int> > pairs;
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
        _fordJohnsonDeque(mainChain);
    
    if (pending.size() > 0)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[0]);
        mainChain.insert(pos, pending[0]);
    }
    //remaining insert
    if (pending.size() > 1)
    {
        std::deque<size_t> insertOrder = _generateInsertionOrderDeque(pending.size());

        for (size_t j = 0; j < insertOrder.size(); j++) {
            size_t idx = insertOrder[j];

            if (idx == 0)
                continue;
            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[idx]);
            mainChain.insert(pos, pending[idx]);
        }
    }

    //insert strgafler
    if (hasStraggler) {
        std::deque<int>::iterator pos =  std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}
