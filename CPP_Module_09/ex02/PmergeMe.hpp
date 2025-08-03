#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>

template <typename Container>
void printContainer(const Container &container) {
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename Container>
void binaryInsert(Container &mainChain, int val) {
    typename Container::iterator it = mainChain.begin();
    while (it != mainChain.end() && *it < val)
        ++it;
    mainChain.insert(it, val);
}

// Templated Ford-Johnson sort
template <typename Container>
void fordJohnsonSort(Container &c) {
    if (c.size() <= 1)
        return;

    Container mainChain;
    Container pend;

    std::vector<std::pair<int, int> > pairs;
    std::size_t i = 0;

    while (i + 1 < c.size()) {
        int a = c[i];
        int b = c[i + 1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
        i += 2;
    }
    if (i < c.size())
        pend.push_back(c[i]);
    Container firsts;
    for (std::size_t j = 0; j < pairs.size(); ++j)
        firsts.push_back(pairs[j].first);
    fordJohnsonSort(firsts);

    for (std::size_t j = 0; j < firsts.size(); ++j)
        mainChain.push_back(firsts[j]);
    for (std::size_t j = 0; j < pairs.size(); ++j)
        pend.push_back(pairs[j].second);
    for (std::size_t j = 0; j < pend.size(); ++j)
        binaryInsert(mainChain, pend[j]);

    c = mainChain;
}

template <typename Container, typename SortFunc>
void testAndPrintSort(Container &container, 
                      SortFunc sortFunc, 
                      const std::string &containerName) {
    std::cout << "Before: ";
    printContainer(container);

    clock_t start = clock();
    sortFunc(container);
    clock_t end = clock();

    std::cout << "After:  ";
    printContainer(container);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << container.size() << " elements with " 
              << containerName << ": ";
    std::cout << ((end - start) * 1000000.0 / CLOCKS_PER_SEC) << " us" << std::endl;
}

int toInt(const std::string &s);

#endif
