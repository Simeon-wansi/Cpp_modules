#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>


template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {};
        MutantStack(MutantStack const &src) {*this = src;}
        ~MutantStack() {};

        MutantStack& operator=(MutantStack const& rhs)
        {
            std::stack<T>::operator=(rhs);
            return *this;
        }

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}
};

#endif