#pragma once

#define SIZE_BLOCK 5

#include <iterator>

// Индексно-последовательный поиск (m = 5)
template <typename T>
T *idxSearch(T *begin, T *end, const T &value)
{
    struct pairIndex
    {
        T kindex;
        unsigned int pindex;
    };
    unsigned int maxpindex = std::abs(std::distance(begin, end) - 1);
    unsigned int sizeINDEX = (maxpindex / SIZE_BLOCK) + 1;
    pairIndex *INDEX = new pairIndex[sizeINDEX];
    for (int i = 0; i < sizeINDEX; ++i)
    {
        INDEX[i].pindex = (i + 1) * SIZE_BLOCK - 1;
        if (INDEX[sizeINDEX - 1].pindex > maxpindex)
        {
            INDEX[sizeINDEX - 1].pindex -= INDEX[sizeINDEX - 1].pindex - maxpindex;
        }
        INDEX[i].kindex = *(begin + INDEX[i].pindex);
    }
    int j = 0;
    while (value > INDEX[j].kindex)
    {
        j += 1;
    }
    for (int i = INDEX[j].pindex - SIZE_BLOCK + 1; i <= INDEX[j].pindex; ++i)
    {
        if (value == *(begin + i))
        {
            return begin + i;
        }
    }
    return nullptr;
}