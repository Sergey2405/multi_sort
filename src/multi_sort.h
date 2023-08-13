#include <iostream>
#include <array>
#include <random>

#define ARRAY_SIZE 10

class MultiSort
{
public:
    MultiSort(int a_size = ARRAY_SIZE);
    virtual ~MultiSort();

    virtual void printArray();
    virtual void sort();

protected:
    int m_iSize;
    int* m_piRandomArray;
};
