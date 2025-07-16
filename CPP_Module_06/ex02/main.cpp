#include <ctime>
#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    int r = rand() % 3;

    if (r == 0) {
        std::cout << "Generated A\n";
        return new A();
    }
    else if (r == 1) {
        std::cout << "Generated B\n";
        return new B();
    }
    else {
        std::cout << "Generated C\n";
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
    } catch (...) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B\n";
        } catch (...) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "C\n";
            } catch (...) {
                std::cout << "Unknown type\n";
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Base* ptr = generate();

    std::cout << "Identify by pointer: ";
    identify(ptr);

    std::cout << "Identify by reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}