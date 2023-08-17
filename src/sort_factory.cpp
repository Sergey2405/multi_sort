#include "sort_factory.h"

SortFactory::SortFactory()
{
    add(new BubbleSort);
    add(new MinMaxSort);
    // std::cout << "Sorts start\n";
    sort();
}

SortFactory::~SortFactory()
{
    //TODO
    //delete other created objects
}

void SortFactory::add(MultiSort* a_pMultiSort)
{
    m_vpMultiSort.push_back(a_pMultiSort);
}

void SortFactory::sort()
{
    for (auto elem : m_vpMultiSort) {
        std::cout << "Sort " << elem->get_type() << std::endl;
        elem->sort();
    }
}

void SortFactory::print()
{
    std::cout << "statisctics:\n";
    for (auto elem : m_vpMultiSort)
        std::cout << "type: " << elem->get_type().data()
                  << ", duration: " << elem->get_duration().count()
                  << std::endl;
    std::cout << std::endl;
}
