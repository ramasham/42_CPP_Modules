#include "BitcoinExchange.hpp"
#include <ctime>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _exchangeRates(other._exchangeRates) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

//in c++98, std::ifstream does not have a constructor that accepts std::string directly
void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: could not open database file.\n";
        std::exit(1);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, rateStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
            continue;

        float rate;
        std::stringstream rateStream(rateStr);
        rateStream >> rate;

        _exchangeRates[trim(date)] = rate;
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    char dash1, dash2;
    std::istringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;
    if (ss.fail() || dash1 != '-' || dash2 != '-')
        return false;
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    static const int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int maxDay = daysInMonth[month - 1];

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        maxDay = 29;
    if (day > maxDay)
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    std::stringstream ss(valueStr);
    ss >> value;

    if (ss.fail() || !ss.eof()) {
        std::cerr << "Error: invalid value format.\n";
        return false;
    }
    if (value < 0) {
        std::cerr << "Error: not a positive number.\n";
        return false;
    }
    if (value > 1000) {
        std::cerr << "Error: too large a number.\n";
        return false;
    }
    return true;
}

std::string BitcoinExchange::getClosestDate(const std::string& date) const {
    if (_exchangeRates.find(date) != _exchangeRates.end())
        return date;

    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
    if (it == _exchangeRates.begin())
        return "";
    --it;
    return it->first;
}

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    if (start == std::string::npos || end == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

//.first -> key(date)
//.second -> value(bitcoin rate)
void BitcoinExchange::processLine(const std::string& line) const {
    std::stringstream ss(line);
    std::string date, valueStr;

    if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
        std::cerr << "Error: bad input => " << line << "\n";
        return;
    }

    date = trim(date);
    valueStr = trim(valueStr);

    float value;
    if (!isValidDate(date)) {
        std::cerr << "Error: bad input => " << date << "\n";
    } else if (!isValidValue(valueStr, value)) {

    } else {
        std::string closest = getClosestDate(date);
        if (closest.empty()) {
            std::cerr << "Error: no earlier date found.\n";
        } else {
            float rate = _exchangeRates.find(closest)->second;
            std::cout << date << " => " << value << " = " << (value * rate) << "\n";
        }
    }
}


void BitcoinExchange::processInputFile(const std::string& inputFile) const {
    std::ifstream file(inputFile.c_str());
    if (!file) {
        std::cerr << "Error: could not open file.\n";
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
        processLine(line);
}
