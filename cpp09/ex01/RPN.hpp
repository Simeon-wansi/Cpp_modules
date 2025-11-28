#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <list>


class RPN{

    private:
        std::stack<int, std::list<int> > _stack;
        bool is_operator(char c);
    
    public:
        RPN();
        ~RPN();
        RPN& operator=(const  RPN& other);
        RPN(const RPN& other);
        int convert(const std::string &str);
};

#endif
