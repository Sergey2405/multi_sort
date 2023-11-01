#ifndef MULTISORT
#define MULTISORT

#include <iostream>
#include <array>
#include <chrono>
#include "sorted_struct.h"

#define DEFAULT_ARRAY_SIZE 1000
typedef SortedStruct SORTED_TYPE;

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
    unsigned long long int getFetchCounter();
    unsigned long long int getCompareCounter();
    unsigned long long int getSwapCounter();

protected:
    int m_iSize;
    T* m_randomArray;
    std::string m_sTypeName;
    std::chrono::microseconds m_duration;
    bool m_bSorted = false;
    unsigned long long int m_iFetchCounter;
    unsigned long long int m_iCompareCounter;
    unsigned long long int m_iSwapCounter;
};

#endif


