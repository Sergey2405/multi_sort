#ifndef SORTED_TYPE_H
#define SORTED_TYPE_H

#include <iostream>

struct SortedStruct
{
    int value;
    std::string description;

    friend bool operator<(const SortedStruct& l, const SortedStruct& r);
    friend bool operator>(const SortedStruct& l, const SortedStruct& r);
    friend std::ostream& operator<<(std::ostream& os, const SortedStruct& obj);
};

#endif
