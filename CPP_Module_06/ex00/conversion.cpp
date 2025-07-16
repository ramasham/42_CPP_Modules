#include <iostream>
#include <iomanip>
#include <cmath>
#include "ScalarConverter.hpp"

//std::cout << std::fixed << std::showpoint << std::setprecision(1);
//is not printing anything by itself — instead,
//it's configuring the output stream std::cout to format floating-point
//numbers differently from that point forward.

void intToAll(int input) {
    std::cout << "char: ";
    char c = static_cast<char>(input);
    if (isprint(c))
        std::cout << c << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: " << input << std::endl;

    float f = static_cast<float>(input);
    double d = static_cast<double>(input);
    std::cout << std::fixed << std::showpoint << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void charToAll(char input) {
    std::cout << "char: " << input << std::endl;

    int i = static_cast<int>(input);
    float f = static_cast<float>(input);
    double d = static_cast<double>(input);

    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::showpoint << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void floatToAll(float input) {
   if (std::isnan(input) || std::isinf(input)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(input) << std::endl;
        return;
    }
    else {
        char c = static_cast<char>(input);
        std::cout << "char: ";
        if (isprint(c))
            std::cout << c << std::endl;
        else
            std::cout << "Non displayable" << std::endl;

        int i = static_cast<int>(input);
        std::cout << "int: " << i << std::endl;
    }

    std::cout << std::fixed << std::showpoint << std::setprecision(1);
    std::cout << "float: " << input << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(input) << std::endl;
}

void doubleToAll(double input) {
   if (std::isnan(input) || std::isinf(input)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(input) << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
        return;
    } else {
        char c = static_cast<char>(input);
        std::cout << "char: ";
        if (isprint(c))
            std::cout << c << std::endl;
        else
            std::cout << "Non displayable" << std::endl;

        int i = static_cast<int>(input);
        std::cout << "int: " << i << std::endl;
    }

    std::cout << std::fixed << std::showpoint << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(input) << "f" << std::endl;
    std::cout << "double: " << input << std::endl;
}
