#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Copy test in scope
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    // Compare with mirror array
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (numbers[i] != mirror[i])
        {
            std::cerr << "Mismatch at index " << i << std::endl;
            delete[] mirror;
            return 1;
        }
    }

    // Test size() function
    std::cout << "Size of numbers: " << numbers.size() << std::endl;

    //test empty array
    Array<int> emptyArray;
    std::cout << "empty array size: " << emptyArray.size() << std::endl;
    try
    {
        emptyArray[0] = 42;
    }
    catch(const std::exception& e)
    {
        std::cout << "Caught exception on empty array access: " << e.what() << std::endl;
    }
    
    // Bounds testing
    try
    {
        numbers[-1] = 42;
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        numbers[MAX_VAL] = 42;
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    delete[] mirror;

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
