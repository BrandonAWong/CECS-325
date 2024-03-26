// Brandon Wong
// CECS 325-02
// Prog 4 - Sorting Contest using pThreads
// Due 03/26/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cout << "Incorrect amount of command line arguments. Try again.\n";
        return -1;
    }
    std::ofstream numbersData {"numbers.dat"};
    std::srand(std::time(0));
    for (std::size_t i {0}; i < std::atoi(argv[1]); ++i)
       numbersData << std::rand() % abs(std::atoi(argv[2]) - std::atoi(argv[3]) - 1) + std::atoi(argv[2]) << '\n'; 
    numbersData.close();
    return 0;
}

