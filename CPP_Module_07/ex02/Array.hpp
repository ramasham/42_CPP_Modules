#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
private:
    T* data;
    unsigned int size_;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    ~Array();

    Array& operator=(const Array& other);

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;
};

template <typename T>
Array<T>::Array() : data(NULL), size_(0) { 
    std::cout << "Default constructor called\n";
}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), size_(n) {
    std::cout << "constructor called\n";
}

template <typename T>
Array<T>::Array(const Array& other) : data(new T[other.size_]), size_(other.size_) {
    for (unsigned int i = 0; i < size_; ++i)
        data[i] = other.data[i];
    std::cout << "copy constructor called\n";
}


template <typename T>
Array<T>::~Array() {
    delete[] data;
    std::cout << "destructor called\n";
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size_ = other.size_;
        data = new T[size_];
        for (unsigned int i = 0; i < size_; ++i)
            data[i] = other.data[i];
    }
    std::cout << "copy assigment constructor called\n";
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= size_)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= size_)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return size_;
}

#endif
