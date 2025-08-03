#include "BitcoinExchange.hpp"
#include <iostream>

//read Bitcoin prices from a reference CSV database,
//and uses those to compute the value of Bitcoin amounts
//from an input file

//You need to:
// - Find the Bitcoin exchange rate for that date from the CSV file.
    // If the exact date doesn't exist, find the closest earlier date.
// - Multiply the (amount) by the (rate)

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    BitcoinExchange btc("data.csv");
    btc.processInputFile(argv[1]);

    return 0;
}
