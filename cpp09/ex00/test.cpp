bool BitcoinExchange::_isValidValue(const std::string& valueStr)
{
    // 1. Check if empty
    if (valueStr.empty())
        return false;
    
    // 2. Convert to double
    char* end;
    double value = std::strtod(valueStr.c_str(), &end);
    
    // 3. Check if conversion succeeded
    if (*end != '\0' && *end != '\n')
        return false;  // Not a valid number
    
    // 4. Check range (must be positive and <= 1000)
    if (value < 0)
        return false;  // Negative
    if (value > 1000)
        return false;  // Too large
    
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    // TODO:
    // 1. Open file
    // 2. Skip first line (header)
    // 3. Read each line
    // 4. Call _parseCsvLine() for each
    // 5. Handle errors (file not found, etc.)
}