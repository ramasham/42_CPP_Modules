#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

template <typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T a, T b) {
    T min = a;
    if (b < a)
        min = b;
    return min;
}

template <typename T>
T max(T a, T b) {
    T max = a;
    if (b > a)
        max = b;
    return max;
}

#endif