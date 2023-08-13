// #include "multi_sort.h"
#include "min_max_sort.h"

// #include <iostream>
// #include <random>

// #define ARRAY_SIZE 1000

std::random_device rd;
std::mt19937 gen(rd());

// int random_array[ARRAY_SIZE];

// void init_random_array(int *a_random_array, int &&a_size)
// {
//     for (int i = 0; i < a_size; i++)
//         a_random_array[i] = rand() % (a_size + 1);
// }

int main()
{
    // init_random_array(random_array, ARRAY_SIZE);
    // for (auto elem : random_array)
    //     std::cout << elem << " ";
    std::cout << "start" << std::endl;
    MinMaxSort minMaxSort;
    std::cout << "minMaxSort" << std::endl;
    MultiSort* pMultiSort = &minMaxSort;
    std::cout << "pMultiSort" << std::endl;

    pMultiSort->printArray();
    std::cout << "printArray" << std::endl;

    pMultiSort->sort();
    std::cout << "sort" << std::endl;

    pMultiSort->printArray();
    std::cout << "printArray" << std::endl;

    return 0;
}
