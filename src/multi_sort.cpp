#include "multi_sort.h"

extern int array_size;

template <typename T>
MultiSort<T>::MultiSort()
{}

template <typename T> 
// void MultiSort::initArray(const int &a_iSize)
void MultiSort<T>::initArray(const int &a_iSize)
{
    if (a_iSize > 0) {
        m_iSize = a_iSize;
        m_piRandomArray = new int[m_iSize];
        for (int i = 0; i < m_iSize; i++)// TODO optimize
            m_piRandomArray[i] = rand() % (m_iSize + 1) + 1;
    }
}

template <typename T>
MultiSort<T>::~MultiSort()
{
    std::cout << "MultiSort::~MultiSort";
}

template <typename T>
void MultiSort<T>::printArray()
{
    for (int i = 0; i < m_iSize; i++)
        std::cout << m_piRandomArray[i] << " ";
    std::cout << std::endl;
}

template <typename T>
std::chrono::microseconds MultiSort<T>::sort()
{
    return m_duration;
}

template <typename T>
bool MultiSort<T>::checkSorted()
{
    bool bSorted = true;
    for(int i = 0; i < m_iSize - 1; i++){
        if (m_piRandomArray[i] > m_piRandomArray[i+ 1]){
            bSorted = false;
            break;
        }
    }
    m_bSorted = bSorted;
    return bSorted;
}

template <typename T>
std::chrono::microseconds MultiSort<T>::getDuration()
{
    return m_duration;
}

template <typename T>
std::string MultiSort<T>::getType()
{
    return m_sTypeName;
}

template <typename T>
bool MultiSort<T>::getSorted()
{
    return m_bSorted;
}
