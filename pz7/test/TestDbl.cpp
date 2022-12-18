#include "idxSearch.hpp"

int TestDbl(int argc, char *argv[])
{
    double *arr = new double[17]{2.1, 5.2, 6.3, 9.4, 12.5, 16.6, 18.7, 20.8, 21.9, 28., 32.1, 39.2, 44.3, 46.4, 51.5, 55.6, 60.7};

    if (idxSearch(arr, arr + 17, 5.2) != nullptr)
        return false;
    else
        return true;
}