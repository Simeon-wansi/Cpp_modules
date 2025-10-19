#include "Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const & src) {
    *this = src;
}

Span::~Span() {}

Span & Span::operator=(Span const & other) {
    if (this != &other) {
        _n = other._n;
        _v = other._v;
    }
    return *this;
}

void Span::addNumber(int nb) {
    if (_v.size() < _n)
        _v.push_back(nb);
    else
        throw NotFoundException();
}

int Span::shortestSpan() {
    if (_v.size() < 2)
        throw NotFoundException();
    
    std::vector<int> sorted_v = _v;
    std::sort(sorted_v.begin(), sorted_v.end());

    std::vector<int> differences;
    std::adjacent_difference(sorted_v.begin(), sorted_v.end(), std::back_inserter(differences));

    return (*std::min_element(differences.begin() + 1, differences.end()));
}

int Span::longestSpan() {
    if (_v.size() < 2)
        throw NotFoundException();

    std::vector<int> sorted_v = _v;
    std::sort(sorted_v.begin(), sorted_v.end());
    return (sorted_v[sorted_v.size() - 1] - sorted_v[0]);
}

