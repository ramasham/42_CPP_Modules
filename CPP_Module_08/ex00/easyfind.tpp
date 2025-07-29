#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
void easyfine(const std::vector<T>& vec, int value) {
    typename std::vector<int>::const_iterator it = 
        std::find(vec.begin(), vec.end(), value);
    
    if (it != vec.end())
        std::cout << "Found at index:" << (it - vec.begin()) << std::endl;
    else
        throw std::out_of_range("Value not found");

}