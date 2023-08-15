#ifndef MULTISORT
#define MULTISORT

#include <iostream>
#include <array>
#include <random>
#include <chrono>

#define DEFAULT_ARRAY_SIZE 1000

class MultiSort
{
public:
    MultiSort();
    virtual ~MultiSort();

    virtual void printArray();
    virtual std::chrono::microseconds sort();
    virtual std::chrono::microseconds get_duration();

protected:
    int m_iSize;
    int* m_piRandomArray;
    std::chrono::microseconds m_duration;
};
#endif
