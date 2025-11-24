#include "RPN.hpp"


RPN::RPN() {}


bool RPN::is_operator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}


RPN::~RPN()
{

}

RPN::RPN(const RPN& other): _stack(other._stack)
{}

RPN& RPN::operator=(const RPN& other)
{
    if (this !=  &other )
    {
        _stack = other._stack;

    }

    return *this;
}


int RPN::convert(const std::string &str)
{
    while (!_stack.empty())
        _stack.pop();

    std::stringstream ss(str); // it's going to parse by tokens
    std::string token;

    while( ss >> token) // will always skip the spaces
    {
        //checking if token is a single digit 

        if(token.length() == 1 && isdigit(token[0]))
        {
            int num = token[0] - '0';
            _stack.push(num);
        }
        //checking if the token is an operator
        else if (token.length() == 1 && is_operator(token[0]))
        {
            // I need 2 operands
            if (_stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }
            int second = _stack.top();
            _stack.pop();
            int first = _stack.top();
            _stack.pop();

            int  result = 0;
            if (token[0] == '+')
                result =  first + second;
            else if (token[0] == '-')
                result =  first - second;
            else if (token[0] == '*')
                result =  first * second;
            else if (token[0] == '/')
            {
                if (second == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return 1;
                }
                result =  first / second;
            }
            _stack.push(result);
        }
        else // no digit or no operator found
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }  
    }

    //making sure I have only 1 elemnt left which is the eresult
    if (_stack.size() != 1)
    {
        std::cerr << "Error " << std::endl;
        return 1;
    }

    std::cout << _stack.top() << std::endl;

    return 0;
}

