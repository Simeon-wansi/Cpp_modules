#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundException: public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Not found!";
        }
};


template <typename T>
typename T::iterator easyfind(T& tab, int b)
{

    typename T::iterator res = std::find(tab.begin(), tab.end(), b);

    if (res == tab.end())
        throw NotFoundException();

    return (res);
}

#endif
