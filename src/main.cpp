#include "min_max_sort.h"
#include "bubble_sort.h"

int array_size;

int main( int argc, char *argv[], char *envp[])
{
    array_size = atoi(argv[1]);
    std::cout << "start array_size=" << array_size << std::endl;
    MinMaxSort minMaxSort;
    BubbleSort bubbleSort;

    MultiSort* pMultiSort = &minMaxSort;
    pMultiSort->sort();
    std::cout << "minMaxSort.sort() duration:" << pMultiSort->get_duration().count() << std::endl;

    pMultiSort = &bubbleSort;
    pMultiSort->sort();
    std::cout << "minMaxSort.sort() duration:" << pMultiSort->get_duration().count() << std::endl;

    return 0;
}
