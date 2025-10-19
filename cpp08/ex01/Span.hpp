#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>


class Span{

private:
    unsigned int _n;
    std::vector<int> _v;

public:
    Span(unsigned int n);
    Span(Span const & src);
    ~Span();
    Span & operator=(Span const & other);
    void addNumber(int nb);

    template <class InputIterator>
    void addNumber(InputIterator begin, InputIterator end);
    int shortestSpan();
    int longestSpan();

    
    class FullException : public std::exception {
        virtual const char* what() const throw() {
            return "Span is full !";
        }
    };
     
    class NotFoundException : public std::exception {
        virtual const char* what() const throw() {
            return "Not found!";
        }
    };

};


template <class InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end) {
    if (_v.size() + std::distance(begin, end) > _n)
        throw FullException();
    _v.insert(_v.end(), begin, end);
}



#endif