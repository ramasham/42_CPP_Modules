#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <string>

template <typename T, typename Func>
void iter(T* arr, size_t length, Func f) {
    for(size_t i = 0; i < length; ++i)
        f(arr[i]);
}

template <typename T, typename Func>
void iter(const T* array, size_t length, Func f) {
    for (size_t i = 0; i < length; ++i)
        f(array[i]);
}

#endif