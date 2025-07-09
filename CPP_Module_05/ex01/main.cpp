#include "Bureaucrat.hpp"

int main() {

    // test_1 -> valid
    std::cout << "--- test 1 ---" << std::endl;
    try {
        Bureaucrat b1("B1", 42);
        std::cout << b1;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    //test_2 -> too low
    std::cout << '\n';
    std::cout << "--- test 2 ---" << std::endl;
    try {
        Bureaucrat b2("B2", 0);
        std::cout << b2;
    }
    catch (const std:: exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    // //test_3 -> too high
    std::cout << '\n';
    std::cout << "--- test 3 ---" << std::endl;
    try
    {
        Bureaucrat b3("B3", 151);
        std::cout << b3;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    // // test_4 -> increment & decrement
    std::cout << '\n';
    std::cout << "--- test 4 ---" << std::endl;
    try {
        Bureaucrat b4("B4", 2);
        std::cout << b4 ;
        b4.increment();
        std::cout << b4;
        b4.increment();
        std::cout << b4;
    }
    catch (const std::exception& e) {
         std::cout << "Exception: " << e.what() << '\n';
    }
    return 0;
}
