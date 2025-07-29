#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <limits>

class Span {
    private:
        std::vector<int> numbers;
        unsigned int maxSize;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        int shortestSpan() const;
        int longestSpan() const;
        void addNumber(int num);

        template <typename T>
        void addNumbersIt(T begin, T end) {
            if (std::distance(begin, end) + numbers.size() > maxSize)
                throw std::runtime_error("Adding range would exceed Span capacity");

            numbers.insert(numbers.end(), begin, end);
        }
};

#endif