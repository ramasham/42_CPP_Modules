
#include "PmergeMe.hpp"

//small wrapper functions for each container
void sortVector(std::vector<int> &v) {
    fordJohnsonSort(v);
}

void sortDeque(std::deque<int> &d) {
    fordJohnsonSort(d);
}

int toInt(const std::string &s) {
    std::istringstream ss(s);
    int n;
    ss >> n;
    if (!ss || !ss.eof() || n < 0)
        throw std::runtime_error("Invalid input");
    return n;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: Please provide at least one input number." << std::endl;
        return 1;
    }

    std::vector<int> inputVec;
    std::deque<int> inputDeq;

    try {
        for (int i = 1; i < argc; ++i) {
            int val = toInt(argv[i]);
            inputVec.push_back(val);
            inputDeq.push_back(val);
        }

        testAndPrintSort(inputVec, sortVector, "std::vector");
        testAndPrintSort(inputDeq, sortDeque, "std::deque");
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
