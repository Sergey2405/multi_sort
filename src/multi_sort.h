#ifndef MULTISORT
#define MULTISORT

#include <iostream>
#include <array>
#include <random>
#include <chrono>

#define DEFAULT_ARRAY_SIZE 1000
// #define TYPENAMESIZE 256;

class MultiSort
{
public:
    MultiSort();
    virtual ~MultiSort();

    virtual void printArray();
    virtual std::chrono::microseconds sort();
    virtual std::chrono::microseconds get_duration();
    std::string get_type();

protected:
    int m_iSize;
    int* m_piRandomArray;
    std::string m_sTypeName;
    std::chrono::microseconds m_duration;
};

#endif
