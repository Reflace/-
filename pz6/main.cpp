#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <cassert>
#include "algo.hpp"
#include <vector>
#include <chrono>
#include <string>
#include <float.h>
#include <iomanip>

using namespace std;

#define MIN_VALUE 0
#define MAX_VALUE 1'000'000

class SortData
{
public:
    float time;
    string name;

    SortData()
    {
        this->time = 0;
        this->name = "";
    }

    SortData(float time, string name)
    {
        this->time = time;
        this->name = name;
    }

    friend bool operator>(SortData sd1, SortData sd2) { return sd1.time > sd2.time; }
    friend bool operator<(SortData sd1, SortData sd2) { return sd1.time < sd2.time; }
    friend bool operator==(SortData sd1, SortData sd2) { return abs(sd1.time - sd2.time) < FLT_EPSILON; }
    friend bool operator!=(SortData sd1, SortData sd2) { return !(sd1 == sd2); }
};

struct PRNG
{
    // Класс mt19937 реализует алгоритм Вихрь Мерсенна.
    std::mt19937 engine;
};

void initGenerator(PRNG &generator)
{
    // Создаём псевдо-устройство для получения случайного зерна.
    std::random_device device;
    generator.engine.seed(device());
}

unsigned random(PRNG &generator, unsigned minValue, unsigned maxValue)
{
    assert(minValue < maxValue);
    // Создаем линейное распределение
    std::uniform_int_distribution<unsigned> distribution(minValue, maxValue);
    return distribution(generator.engine);
}

inline void copyArray(int *from, int *to, int size)
{
    for (int i = 0; i < size; i++)
        to[i] = from[i];
}

inline void initArray(int *array, int n, PRNG &generator, int minValue, int maxValue)
{
    for (unsigned int i = 0; i < n; i++)
    {
        array[i] = random(generator, minValue, maxValue);
    }
}

inline void printArray(int* array, int n, PRNG &generator)
{
    cout << std::endl;
    if (n <= 10)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << endl;
    }
    else
    {
        int startPoint = random(generator, 0, n - 10);
        for (int i = startPoint; i < startPoint + 10; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << endl;
    }
}

int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

bool compInt(int a, int b)
{
    return a < b;
}

bool compFlt(SortData a, SortData b)
{
    return a.time < b.time;
}

int main()
{
    PRNG generator;
    initGenerator(generator);

    int size = 10'000'000;
    int *array = new int[size];

    SortData *mySD = new SortData[4];
    SortData *stlSD = new SortData[4];

    for (int i = 0; i < 4; ++i)
    {
        initArray(array, size, generator, MIN_VALUE, MAX_VALUE);
        auto start = chrono::high_resolution_clock::now();
        switch (i)
        {
        case 0:
            QuickSort(array, 0, size);
            mySD[i].name = "My QuickSort";
            break;
        case 1:
            QuickSortModified(array, 0, size);
            mySD[i].name = "My QuickSortModified";
            break;
        case 2:
            MergeSort(array, size);
            mySD[i].name = "My MergeSort";
            break;
        case 3:
            MergeSortRecursive(array, size);
            mySD[i].name = "My MergeSortRecursive";
        default:
            break;
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float> duration = end - start;
        mySD[i].time = duration.count();
        // std::cout << mySD[i].name << ": " << mySD[i].time << endl;
    }
    for (int i = 0; i < 4; i++)
    {
        initArray(array, size, generator, MIN_VALUE, MAX_VALUE);
        auto start = chrono::high_resolution_clock::now();
        switch (i)
        {
        case 0:
            std::qsort(array, size, sizeof(int), comp);
            stlSD[i].name = "STL qsort";
            break;
        case 1:
            std::sort(array, array + size, compInt);
            stlSD[i].name = "STL sort";
            break;
        case 2:
            std::stable_sort(array, array + size, compInt);
            stlSD[i].name = "STL stable_sort";
            break;
        case 3:
            std::partial_sort(array, array + size / 2, array + size, compInt);
            stlSD[i].name = "STL partial_sort";
        default:
            break;
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float> duration = end - start;
        stlSD[i].time = duration.count();
        // std::cout << stlSD[i].name << ": " << stlSD[i].time << endl;
    }

    std::sort(mySD, mySD + 4, compFlt);
    std::sort(stlSD, stlSD + 4, compFlt);

    SortData* resultSD = new SortData[8];
    std::merge(mySD, mySD +  4, stlSD, stlSD + 4, resultSD);

    cout << "\tTop sorts:\n";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << left << std::setw(30) << resultSD[i].name << ": " << resultSD[i].time << std::endl;
    }

    return 0;
}