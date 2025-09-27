#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter&){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&){return *this;}

ScalarConverter::~ScalarConverter() {};

bool ScalarConverter::isChar(const std::string& literal) {
    return ((literal.length() == 3 && 
            literal[0] == '\'' &&
            literal[2] == '\'' && 
            std::isprint(literal[1])));
}


bool ScalarConverter::isInt(const std::string& literal)
{
    char *end;
    errno = 0;
    long val = std::strtol(literal.c_str(), &end, 10);

    return (*end == '\0' && errno == 0 && 
        val >= INT_MIN && val <= INT_MAX &&
            literal.find('.') == std::string::npos);
}


bool ScalarConverter::isFloat(const std::string& literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;

    if (literal.empty() || literal[literal.length() -1] != 'f')
        return false;

    std::string without_f =  literal.substr(0, literal.length() - 1);
    char* end;
    errno = 0;
    std::strtof(without_f.c_str(), &end);

    return (*end == '\0' && errno == 0);
}


bool ScalarConverter::isDouble(const std::string& literal){
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;

    char* end;
    errno = 0;
    std::strtod(literal.c_str(), &end);

    return (*end == '\0' && errno == 0);
}
void ScalarConverter::convert(std::string const& literal){

    double value = 0;

    //determine what type  and get the value
    if (isChar(literal))
        value = static_cast<double>(literal[1]);
    else if (isInt(literal))
        value = static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
    else if (isFloat(literal)){
        if (literal == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inff")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inff")
            value = -std::numeric_limits<double>::infinity();
        else 
            value = static_cast<double>(std::strtof(literal.c_str(), NULL));
    }
    else if (isDouble(literal))
    {
        if (literal == "nan")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf")
            value = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            value = -std::numeric_limits<double>::infinity();
        else
            value = std::strtod(literal.c_str(), NULL);
    }
    else {
        std::cout << "Error : invalid Literal";
        return;
    }

    // print all conversions
    printChar(value); 
    printInt(value);
    printFloat(value);
    printDouble(value);
}


void ScalarConverter::printChar(double value) {
    std::cout <<"char: ";
    if (std::isnan(value) || std::isinf(value) ||
        value < 0 || value > 127)
            std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value){
    std::cout <<"int: ";
    if (std::isnan(value) || std::isinf(value) ||
        value < INT_MIN || value > INT_MAX)
            std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
    std::cout <<"float: ";

    //checking for specials value first
    if (std::isnan(value))
    {
        std::cout<< "nanf" <<std::endl;
        return;
    }
    if (std::isinf(value))
    {
        if (value > 0)
            std::cout <<"+inff" <<std::endl;
        else
            std::cout <<"-inff" << std::endl;
        return;
    }

    //checking the range
    if (value > std::numeric_limits<float>::max() ||
        value < std::numeric_limits<float>::lowest()){
            std::cout <<"impossible" << std::endl;
            return;
    }

    //convert and print float 
    float f_value =  static_cast<float>(value);
    std::cout << f_value;

    // adding 'f' and ensure 1 decimal place if it's a whole number
    if (f_value == static_cast<int>(f_value))
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
}


void ScalarConverter::printDouble(double value)
{
    std::cout <<"double: ";

    //spcial value check
    if (std::isnan(value))
    {
        std::cout << "nan" << std::endl;
        return;
    }
    if (std::isinf(value))
    {
        if (value > 0)
            std::cout <<"+inf" <<std::endl;
        else
            std::cout << "-inf" <<std::endl;
        return;
    }

    //range check
    if (value > std::numeric_limits<double>::max() ||
        value < std::numeric_limits<double>::lowest()){
            std::cout <<"impossible" << std::endl;
            return;
    }

    // convert and print
    double d_value =  static_cast<double>(value);
    std::cout << d_value;

    if (d_value == static_cast<int>(d_value))
        std::cout << ".0" << std::endl;
    else
        std::cout << std::endl;
}