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
    bool checkSorted();

    virtual std::chrono::microseconds getDuration();
    std::string getType();
    bool getSorted();

protected:
    int m_iSize;
    int* m_piRandomArray;
    std::string m_sTypeName;
    std::chrono::microseconds m_duration;
    bool m_bSorted = false;
};

#endif
