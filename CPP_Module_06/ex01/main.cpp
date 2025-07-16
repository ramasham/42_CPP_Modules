
#include <iostream>
#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data original;
    original.id = 42;
    original.name = "Rama";

    // Print original pointer
    std::cout << "Original pointer: " << &original << "\n";
    std::cout << "Original data: ID = " << original.id << ", Name = " << original.name << "\n";

    // Serialize the pointer
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized (uintptr_t): " << raw << "\n";

    // Deserialize back to a pointer
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << deserialized << "\n";
    std::cout << "Deserialized data: ID = " << deserialized->id << ", Name = " << deserialized->name << "\n";

    return 0;
}
