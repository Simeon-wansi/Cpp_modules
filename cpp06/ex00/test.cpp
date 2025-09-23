#include "ScalarConverter.hpp"
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cmath>

// Private constructors - keep them empty since class can't be instantiated
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

// Check if it's a single character literal like 'a'
bool ScalarConverter::isChar(const std::string& literal) {
    return (literal.length() == 3 && 
            literal[0] == '\'' && 
            literal[2] == '\'' &&
            std::isprint(literal[1]));
}

// Check if it's a valid integer
bool ScalarConverter::isInt(const std::string& literal) {
    char* end;
    errno = 0;
    long val = std::strtol(literal.c_str(), &end, 10);
    
    return (*end == '\0' && errno == 0 && 
            val >= INT_MIN && val <= INT_MAX &&
            literal.find('.') == std::string::npos);
}

// Check if it's a valid float (ends with 'f')
bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
    
    if (literal.empty() || literal[literal.length() - 1] != 'f')
        return false;
    
    char* end;
    errno = 0;
    std::strtof(literal.c_str(), &end);
    
    return (*end == 'f' && *(end + 1) == '\0' && errno == 0);
}

// Check if it's a valid double
bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
    
    char* end;
    errno = 0;
    std::strtod(literal.c_str(), &end);
    
    return (*end == '\0' && errno == 0 && literal.find('.') != std::string::npos);
}

// Main conversion function
void ScalarConverter::convert(const std::string& literal) {
    double value = 0;
    
    // Determine the type and get the value
    if (isChar(literal)) {
        value = static_cast<double>(literal[1]);
    }
    else if (isInt(literal)) {
        value = static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
    }
    else if (isFloat(literal)) {
        if (literal == "nanf") value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inff") value = std::numeric_limits<double>::infinity();
        else if (literal == "-inff") value = -std::numeric_limits<double>::infinity();
        else value = static_cast<double>(std::strtof(literal.c_str(), NULL));
    }
    else if (isDouble(literal)) {
        if (literal == "nan") value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf") value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf") value = -std::numeric_limits<double>::infinity();
        else value = std::strtod(literal.c_str(), NULL);
    }
    else {
        std::cout << "Error: invalid literal" << std::endl;
        return;
    }
    
    // Now print all conversions
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || 
        value < 0 || value > 127) {
        std::cout << "impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<int>(value))) {
        std::cout << "Non displayable" << std::endl;
    }
    else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
}


void ScalarConverter::printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) ||
        value < INT_MIN || value > INT_MAX) {
        std::cout << "impossible" << std::endl;
    }
    else {
        std::cout << static_cast<int>(value) << std::endl;
    }
}