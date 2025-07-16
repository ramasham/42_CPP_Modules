#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cctype>
#include <cmath>

#include "ScalarConverter.hpp"

enum ScalarType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    OTHER
};

bool isChar(const std::string& input) {
    return input.length() == 1;
}

bool isInt(const std::string& input) {
    std::istringstream ss(input);
    int res;
    ss >> res;
    ss >> std::ws;
    return !ss.fail() && ss.eof();
}

bool isFloat(const std::string& input) {
    if (input == "-inff" || input == "+inff" || input == "nanf")
        return true;

    if (input.empty() || input[input.length() - 1] != 'f')
        return false;

    std::string numericPart = input.substr(0, input.length() - 1);
    if (numericPart.empty())
        return false;
    std::istringstream ss(numericPart);
    float res;
    ss >> res;
    return !ss.fail() && ss.eof();
}

bool isDouble(const std::string& input) {
    if (input == "-inf" || input == "+inf" || input == "nan")
        return true;

    if (input.empty())
        return false;

    std::istringstream ss(input);
    double res;
    ss >> res;
    return !ss.fail() && ss.eof();
}

ScalarType detectType(const std::string& input) {
    if (isInt(input))
        return INT;
    if (isChar(input))
        return CHAR;
    if (isFloat(input))
        return FLOAT;
    if (isDouble(input))
        return DOUBLE;
    return OTHER;
}

static int toInt(const std::string& str) {
    std::stringstream ss(str);
    int res = 0;
    ss >> res;
    return res;
}

static char toChar(const std::string& str) {
    return str[0];
}

static float toFloat(const std::string& str) {
    if (str == "nanf")
        return std::numeric_limits<float>::quiet_NaN();
    if (str == "+inff")
        return std::numeric_limits<float>::infinity();
    if (str == "-inff")
        return -std::numeric_limits<float>::infinity();

    std::stringstream ss(str);
    float res;
    ss >> res;
    return res;
}

static double toDouble(const std::string& str) {
    if (str == "nan")
        return std::numeric_limits<double>::quiet_NaN();
    if (str == "+inf")
        return std::numeric_limits<double>::infinity();
    if (str == "-inf")
        return -std::numeric_limits<double>::infinity();

    std::stringstream ss(str);
    double res;
    ss >> res;
    return res;
}

void handleType(const std::string& input) {
    switch (detectType(input)) {
        case CHAR: {
            char res = toChar(input);
            charToAll(res);
            break;
        }
        case INT: {
            int res = toInt(input);
            intToAll(res);
            break;
        }
        case FLOAT: {
            float res = toFloat(input);
            floatToAll(res);
            break;
        }
        case DOUBLE: {
            double res = toDouble(input);
            doubleToAll(res);
            break;
        }
        default:
            std::cout << "Type: unknown\n";
    }
}
