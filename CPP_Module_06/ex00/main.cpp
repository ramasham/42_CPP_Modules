#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc == 2) {
        std::string input(argv[1]);
        ScalarConverter::convert(input);
        return (0);
    }
    std::cerr << "Enter string to convert" << std::endl;
    return (1);
}