#include "bort_factory.h"
// #include "min_max_sort.h"
// #include "bubble_sort.h"

int array_size;

int main( int argc, char *argv[], char *envp[])
{
    array_size = atoi(argv[1]);
    SortFactory sortFactory;
    sortFactory.print();

    return 0;
}
