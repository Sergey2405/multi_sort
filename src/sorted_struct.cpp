#include "sorted_struct.h"

// SortedStruct& operator>
bool operator<(const SortedStruct& l, const SortedStruct& r)
{
    return l.value < r.value ? true : false;
}

bool operator>(const SortedStruct& l, const SortedStruct& r)
{
    return l.value > r.value ? true : false;
}

std::ostream& operator<<(std::ostream& os, const SortedStruct& obj)
{
    return os << obj.value << " " << obj.description << " ";
}
