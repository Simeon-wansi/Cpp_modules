#include "BitcoinExchange.hpp"
#include <fstream> // for file I/O
#include <sstream> // for string parsing
#include <string> // for string operation 
#include <cstdlib>  // for atof() or use <string> for stod()
#include <limits>  // for numerics limits 


const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;

// return tru if year i  multiple of 4 and not mutiple o 100
//or year is multiple of 400


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other):_database(other._database)
{

}

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange() 
{
    // std::cout<<"Destructor"<<std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if(this != &src)
    {
        _database =  src._database;
    }

    return *this;
}

bool BitcoinExchange::_isLeap(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) ||
            (year % 400 == 0));
}

std::string BitcoinExchange::_trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first ==  std::string::npos)
        return ""; // all whitespaces
    
    size_t last = str.find_last_not_of(" \t\n\r");

    return str.substr(first, last - first + 1);
}

bool BitcoinExchange::_isValidDate(const std::string& date)
{

    // Check length (10 chars)
    if (date.length() != 10)
        return false;

    // check the date format , dashes at position 4 and 7
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    //check all other chars are digitis 
    for (int i = 0; i < 10 ; i++){
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    // extract values
    int year = std::atoi(date.substr(0, 4).c_str());
    int month =  std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());


    // validates ranges 
    if (year < MIN_VALID_YR || year > MAX_VALID_YR)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    // check days in month 

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (_isLeap(year))
        daysInMonth[1] =  29;

    if (day > daysInMonth[month - 1])
        return false;
    
    return true;
}


bool BitcoinExchange::_isValidValue(const std::string& valueStr)
{
    if (valueStr.empty())
        return false;

    // converst to double
    char* end;
    double value =  std::strtod(valueStr.c_str(), &end);

    while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')
        end++;

    // check if the conversion succeeded
    if (*end != '\0')
        return false;

    if (value > 1000 || value < 0)
        return false;
    
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: can't open file " << filename << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while(std::getline(file, line))
    {
        _parseCsvLine(line);
    }
    file.close();
}

void BitcoinExchange::_parseCsvLine(const std::string& line)
{
    size_t pos =  line.find(',');

    if (pos == std::string::npos){
        std::cerr << "Error: bad input =>" << line << std::endl;
        return;
    }
    std::string date = line.substr(0, pos);
    std::string strValue = line.substr(pos + 1);
    
    // if (!_isValidDate(date) || !_isValidValue(strValue))
    // {
    //     std::cerr << "Date or BTC value not valid - 1! " << std::endl;
    //     return;
    // }

    double value = std::atof(strValue.c_str());

    _database[date] =  value;
}

double BitcoinExchange::_findExchangeRate(const std::string& date, bool& found)
{
    std::map<std::string, double>::iterator it = _database.find(date);

    if (it != _database.end())
    {
        found =  true;
        return it->second;
    }
    
    std::map<std::string, double>::iterator it_up = _database.upper_bound(date);

    if(it_up == _database.begin())
    {
        found =  false;
        return 0.0;
    }

    --it_up;
    found = true;
    return it_up->second;;
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: can't open file " << filename <<std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while(getline(file, line))
    {
        _processInputLine(line);
    }
    file.close();
}

void BitcoinExchange::_processInputLine(const std::string& line)
{
    size_t pos =  line.find('|');

    if (pos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date =  _trim(line.substr(0, pos));
    std::string strValue  = _trim(line.substr(pos + 1));

    if (!_isValidDate(date))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return;
    }

    if (!_isValidValue(strValue))
    {
        char *end;
        double testValue = std::strtod(strValue.c_str(), &end);

        // checking if it a valid number first
        if (*end != '\0' && *end != '\n' && *end != '\0')
            std::cerr << "Error: bad input => " << strValue << std::endl;
        else if (testValue < 0)
            std::cerr << "Error: not  positive number." << std::endl;
        else if (testValue > 1000)
            std::cerr << "Error: too large number." << std::endl;
        return;
    }

    if (_database.empty())
    {
        std::cerr << "Error: database is empty." << std::endl;
        return;
    }

    double value =  std::atof(strValue.c_str());

    //find exchange rate 
    bool found = false;
    double rate = _findExchangeRate(date, found);

    if (!found)
    {
        std::cerr << "Error: date too early." << std::endl;
        return;
    }
    // calculate and print
    double result =  value * rate;
    std::cout << date << " => " << value << " = " << result << std::endl;
}

