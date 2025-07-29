#include <iostream>
#include <vector>
#include "Span.hpp"

void testAddNumber() {
    std::cout << "---- Add numbers ---- \n";
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testAddNumbersIt() {
    std::cout << "---- Add numbers using range ---- \n";
    try {
        Span sp(10000);

        std::vector<int> data(10000);
        for (int i = 0; i < 10000; ++i)
            data[i] = i;

        sp.addNumbersIt(data.begin(), data.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    testAddNumber();
    testAddNumbersIt();

    return 0;
}
