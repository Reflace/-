#include "idxSearch.hpp"

int TestInt(int argc, char *argv[])
{
    int *arr = new int[17]{2, 5, 6, 9, 12, 16, 18, 20, 21, 28, 32, 39, 44, 46, 51, 55, 60};

    if (idxSearch(arr, arr + 17, 5) != nullptr)
        return false;
    else
        return true;
}