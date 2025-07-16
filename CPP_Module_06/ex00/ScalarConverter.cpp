#include "ScalarConverter.hpp"
#include <sstream>
#include <string>
#include <iostream>


ScalarConverter::ScalarConverter() {
    std::cout << "Default constructor called";
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
    std::cout << " Copy constructor called\n";
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    std::cout << "Copy assignment operator called\n";
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called\n";
}

void ScalarConverter::convert(const std::string& input) {
    handleType(input);
}
