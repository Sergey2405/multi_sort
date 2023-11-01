#ifndef SORTED_TYPE_H
#define SORTED_TYPE_H

#include <iostream>

struct SortedStruct
{
    int m_iValue;
    int m_iPosition;
    std::string description;

    void setValue(int a_Ix, int a_iRange);

    friend bool operator<(const SortedStruct& l, const SortedStruct& r);
    friend bool operator>(const SortedStruct& l, const SortedStruct& r);
    friend std::ostream& operator<<(std::ostream& os, const SortedStruct& obj);
};

#endif
