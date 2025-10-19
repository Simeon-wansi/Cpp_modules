#include "Span.hpp"


int main()
{
    Span sp(5);

    sp.addNumber(10);
    sp.addNumber(5);
    sp.addNumber(20);
    sp.addNumber(6);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp2 = Span(9);

    std::vector<int> v;
    v.push_back(11);
    v.push_back(23);
    v.push_back(32);
    v.push_back(96);
    v.push_back(78);

    sp2.addNumber(v.begin(), v.end());
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    return 0;
}