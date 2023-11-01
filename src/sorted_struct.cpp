#include <random>
#include <chrono>

#include "sorted_struct.h"

void SortedStruct::setValue(int a_Ix, int a_iRange)
{
    m_iValue = rand() % (a_iRange + 1) + 1;
    m_iPosition = a_Ix;
    // description = "";
}

bool operator<(const SortedStruct& l, const SortedStruct& r)
{
    return l.m_iValue < r.m_iValue ? true : false;
}

bool operator>(const SortedStruct& l, const SortedStruct& r)
{
    return l.m_iValue > r.m_iValue ? true : false;
}

std::ostream& operator<<(std::ostream& os, const SortedStruct& obj)
{
    return os << obj.m_iValue << " " << obj.m_iPosition << " " << obj.description << "\t";
}
