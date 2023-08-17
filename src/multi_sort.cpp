#include "multi_sort.h"

extern int array_size;

MultiSort::MultiSort()
{
    m_iSize = array_size;
    m_piRandomArray = new int[m_iSize];
    for (int i = 0; i < m_iSize; i++)// TODO optimize
        m_piRandomArray[i] = rand() % (m_iSize + 1);
}

MultiSort::~MultiSort()
{
    std::cout << "MultiSort::~MultiSort";
}

void MultiSort::printArray()
{
    std::cout << "MinMaxSort::printArray" << std::endl;
    for (int i = 0; i < m_iSize; i++)
        std::cout << m_piRandomArray[i] << " ";
    std::cout << std::endl;
}

std::chrono::microseconds MultiSort::sort()
{
    return m_duration;
}

std::chrono::microseconds MultiSort::get_duration()
{
    return m_duration;
}

std::string MultiSort::get_type()
{
    return m_sTypeName;
}
