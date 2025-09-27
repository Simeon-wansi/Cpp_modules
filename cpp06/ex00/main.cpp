#include "ScalarConverter.hpp"




int main(int ac, char **av)
{
    // ScalarConverter::convert("42"); 
    // ScalarConverter::convert("42.0f");   
    // ScalarConverter::convert("'a'"); 
    if (ac != 2)
    {
        std::cerr << "Error: " << av[0] << " <literal>" << std::endl;
        return 1;
    }

    ScalarConverter::convert(av[1]);
    return 0;
}