#include "Serializer.hpp"
#include <iostream>


//Serialization ->
//Convert an object into a format for storage/transmission
//uses ->
//Data Storage: Serialization is used to save the state of an object or data structure to a file or database.
//Data Transmission: Serialized data can be sent over a network or between different systems.

//uintptr_t an unsigned integer type specifically designed to hold a memory address

Serializer::Serializer() {
    std::cout << "Default constructor called\n";
}

Serializer::Serializer(const Serializer& other) {
    (void)other;
    std::cout << "Copy constructor called\n";
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    std::cout << "Copy assignment operator called\n";
    return *this;
}

Serializer::~Serializer() {
    std::cout << "Destructor called\n";
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}