// Brandon Wong
// CECS 325-02
// Prog 3 - Sorting Contest 
// Due 03/12/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>

void bubble(int A[], int size)
{
    int temp {};
    for (std::size_t i {0}; i < size; ++i)
    {
        for (std::size_t j {i+1}; j < size; ++j)
            if (A[i] > A[j])
            {
                temp = {A[i]};
                A[i] = A[j];
                A[j] = temp;
            }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Incorrect amount of command line arguments. Try again\n";
        return -1;
    }
    std::ifstream numbersData {argv[1]};
    int numbers[1000000];
    std::size_t counter {0};
    std::string num {};
    while (std::getline(numbersData, num, '\n'))
    {
        if (counter < 1000000)
            numbers[counter++] = std::stoi(num);
        else
        {
            std::cout << "Max amount of numbers reached. Try again\n";
            return -1;
        }
    }
    numbersData.close(); 
    bubble(numbers, counter);
    std::ofstream outputData {argv[2]};
    for (std::size_t i {0}; i < counter; ++i)
        outputData << numbers[i] << '\n';
    outputData.close();
    return 0;
}

