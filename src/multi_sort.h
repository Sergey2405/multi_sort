#ifndef MULTISORT
#define MULTISORT

#include <iostream>
#include <array>
#include <random>
#include <chrono>

// #include "multi_sort.cpp"
// #include "bu"

#define DEFAULT_ARRAY_SIZE 1000

template <typename T>
class MultiSort
{
public:
    MultiSort();
    virtual ~MultiSort();

    void initArray(const int &a_iSize);
    virtual void printArray();
    virtual std::chrono::microseconds sort();
    bool checkSorted();

    virtual std::chrono::microseconds getDuration();
    std::string getType();
    bool getSorted();

protected:
    int m_iSize;
    // int* m_piRandomArray;
    T* m_piRandomArray;
    std::string m_sTypeName;
    std::chrono::microseconds m_duration;
    bool m_bSorted = false;
};

#endif
