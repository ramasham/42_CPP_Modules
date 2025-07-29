#include "easyfind.hpp"
#include <stdexcept>

int main() {
    int arr[] = {1, 2, 3, 5, 5};
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    try {
        easyfine(v, 5);
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}