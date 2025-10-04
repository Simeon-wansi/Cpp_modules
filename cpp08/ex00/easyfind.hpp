#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

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
  


    for (typename T::iterator it = tab.begin(); it != tab.end(); ++it)
    {
        if (*it == b)
            return it;
    }

    throw NotFoundException();
}


#endif