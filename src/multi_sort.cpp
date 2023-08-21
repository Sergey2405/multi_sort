#include "multi_sort.h"

extern int array_size;

MultiSort::MultiSort()
{
    m_iSize = array_size;
    m_piRandomArray = new int[m_iSize];
    for (int i = 0; i < m_iSize; i++)// TODO optimize
        m_piRandomArray[i] = rand() % (m_iSize + 1) + 1;
}

MultiSort::~MultiSort()
{
    std::cout << "MultiSort::~MultiSort";
}

void MultiSort::printArray()
{
    for (int i = 0; i < m_iSize; i++)
        std::cout << m_piRandomArray[i] << " ";
    std::cout << std::endl;
}

std::chrono::microseconds MultiSort::sort()
{
    return m_duration;
}

bool MultiSort::checkSorted()
{
    bool bSorted = true;
    // std::cout << "MultiSort::checkSorted() ";printArray(); std::cout << std::endl; //remove
    for(int i = 0; i < m_iSize - 1; i++){
        if (m_piRandomArray[i] > m_piRandomArray[i+ 1]){
            bSorted = false;
            break;
        }
    }
    m_bSorted = bSorted;
    return bSorted;
}

std::chrono::microseconds MultiSort::getDuration()
{
    return m_duration;
}

std::string MultiSort::getType()
{
    return m_sTypeName;
}

bool MultiSort::getSorted()
{
    return m_bSorted;
}
