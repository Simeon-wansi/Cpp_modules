#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>


class RPN{

    private:
        std::stack<int> _stack;
        bool is_operator(char c);
    
    public:
        RPN();
        ~RPN();
        RPN& operator=(const  RPN& other);
        RPN(const RPN& other);
        int convert(const std::string &str);
};


#endif

// 1 * 2 / 2 * 2 2 - 4 +

// 7 * 7 - 7 = 42 

// 8 * 9 - 9 -9 - 9 - 4 + 1 = 