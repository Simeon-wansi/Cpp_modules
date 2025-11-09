#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>


class BitcoinExchange{
private:
    std::map<std::string, double> _database;

    bool _isLeap(int year);
    bool _isValidDate(const std::string& date);
    bool _isValidValue(const std::string& valueStr);
    double _findExchangeRate(const std::string& date, bool& found);
    void _parseCsvLine(const std::string& line);
    void _processInputLine(const std::string& line);
    std::string _trim(const std::string& str);
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& src);
    ~BitcoinExchange();


    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename);
};


#endif