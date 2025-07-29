#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span() : maxSize(0) {
    std::cout << "Default constructor called\n";
}

Span::Span(unsigned int N) : maxSize(N) {
    std::cout << "constructor called\n";
}

Span::~Span() {
    std::cout << "Destructor called\n";
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->maxSize = other.maxSize;
        this->numbers = other.numbers;
    }
    std::cout << "copy assignment constructor called\n";
    return *this;
}

Span::Span(const Span& other)
    : numbers(other.numbers), maxSize(other.maxSize) {
        std::cout << "copy constructor called\n";
}

void Span::addNumber(int num) {
    if (numbers.size() >= maxSize)
        throw std::runtime_error("Span is full!");
    numbers.push_back(num);
}

//minimum difference between any two numbers
int Span::shortestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers for a span");
    
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for(size_t i = 1; i < sorted.size(); ++i)
        minSpan = std::min(minSpan, sorted[i] - sorted[i - 1]);
    return minSpan;
}

//difference between the maximum and minimum
int Span::longestSpan() const {
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers for a span");
    
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}
