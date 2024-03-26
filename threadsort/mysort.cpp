// Brandon Wong
// CECS 325-02
// Prog 4 - Sorting Contest using pThreads
// Due 03/28/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <pthread.h>

struct SectionInfo
{
    int *start {nullptr};
    std::size_t size {0};
};

void bubble(int A[], std::size_t size)
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

void merge(int arr1[], std::size_t size1, int arr2[], std::size_t size2)
{
    int temp[size1+size2];
    std::size_t i {0}, currentIndex1 {0}, currentIndex2 {0};
    while (currentIndex1 < size1 and currentIndex2 < size2)
    {
        temp[i++] =  (arr1[currentIndex1] < arr2[currentIndex2]) ? arr1[currentIndex1++] : arr2[currentIndex2++];
    }
    while (currentIndex1 < size1)
        temp[i++] =  arr1[currentIndex1++];
    while (currentIndex2 < size2)
        temp[i++] =  arr2[currentIndex2++];

    for (std::size_t i {0}; i < size1+size2; ++i)
       arr1[i] = temp[i]; 
}

void *bridge(void *section)
{
    SectionInfo *info = static_cast<SectionInfo*>(section);
    bubble(info->start, info->size);
    return nullptr;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Incorrect amount of command line arguments. Try again\n";
        return -1;
    }
    std::ifstream numbersData {argv[1]};
    int *numbers = new int[1000000];
    std::size_t length {0};
    std::string num {};
    while (std::getline(numbersData, num, '\n'))
    {
        if (length < 1000000)
            numbers[length++] = std::stoi(num);
        else
        {
            std::cout << "Max amount of numbers reached. Try again\n";
            return -1;
        }
    }
    numbersData.close(); 
    
    pthread_t threads[8];
    SectionInfo sections[8];

    for (std::size_t i {0}; i < 8; ++i)
    {
        sections[i].start = &numbers[length/8*(i)];
        sections[i].size = (i == 7 and length % 8) ? length / 8 + length % 8 : length / 8;
        pthread_create(&threads[i], NULL, bridge, (void *) &sections[i]);
    }

    for (pthread_t &thread : threads)
        pthread_join(thread, NULL);

    std::size_t i {0}, k {0};
    int merge_round {1};
    while (merge_round < 4)
    {
       merge(sections[i].start, sections[i].size, sections[i+1].start, sections[i+1].size);
       sections[k].start = sections[i].start;
       sections[k++].size = sections[i].size + sections[i+1].size;
       i += 2;
       if (i >= 8 / merge_round)
       {
           i = k = 0;
           ++merge_round;
       }
    }

    std::ofstream outputData {argv[2]};
    for (std::size_t i {0}; i < length; ++i)
        outputData << numbers[i] << '\n';
    outputData.close();

    delete[] numbers;
    return 0;
}

