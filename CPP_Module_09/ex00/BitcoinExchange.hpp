#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, float> _exchangeRates;

    void processLine(const std::string& line) const;
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr, float& value) const;
    std::string getClosestDate(const std::string& date) const;
    std::string trim(const std::string& str) const;

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& dbFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInputFile(const std::string& inputFile) const;
};

#endif
