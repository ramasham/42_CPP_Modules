#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    
    public:
        static void convert(const std::string& input);
};

void handleType(const std::string& input);
void intToAll(int input);
void charToAll(char input);
void floatToAll(float input);
void doubleToAll(double input);

#endif