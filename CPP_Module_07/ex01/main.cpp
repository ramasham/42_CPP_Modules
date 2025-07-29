#include <iostream>
#include <string>
#include "iter.hpp"

void add(int& n) {
    n *= 10;
}

void addChar(char& c) {
    c = c - 32;
}

void print(const std::string& val) {
    std::cout << val << " ";
}

int main() {
    int arrNum[] = {1, 2, 3, 4};
    char arrChar[] = {'a', 'b', 'c'};

    size_t lenNum = sizeof(arrNum) / sizeof(arrNum[0]);
    size_t lenChar = sizeof(arrChar) / sizeof(arrChar[0]);

    std::cout << "Multiply numbers by 10: ";
    iter(arrNum, lenNum, ::add);
    for(size_t i = 0; i < lenNum; ++i)
        std::cout << arrNum[i] << " " ;

    std::cout << "\nUppercase: ";
    iter(arrChar, lenChar, ::addChar);
    for(size_t i = 0; i < lenChar; ++i)
        std::cout << arrChar[i] << " ";
    
    std::cout << "\nRead-only const test: ";
    const std::string constWords[] = {"hello", "world", "const"};
    size_t lenWords = sizeof(constWords) / sizeof(constWords[0]);
    iter(constWords, lenWords, print);
}
