#ifndef SCALARCONVERTER_HPP 
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <climits>

class ScalarConverter {

private:
    // prevent intatiation
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

    //helper methos
    static bool isInt(const std::string& literal);
    static bool isChar(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);

    //conversion helpers 
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);

public:
    static void convert(std::string const& literal);
    
};

#endif

