#include "min_max_sort.h"

int array_size;

int main( int argc, char *argv[], char *envp[] )
{
    array_size = atoi(argv[1]);
    std::cout << "start array_size=" << array_size << std::endl;
    MinMaxSort minMaxSort;
    std::cout << "minMaxSort" << std::endl;
    MultiSort* pMultiSort = &minMaxSort;
    std::cout << "pMultiSort" << std::endl;

    pMultiSort->sort();
    std::cout << "sort() duration:" << pMultiSort->get_duration().count() << std::endl;
    
    return 0;
}
