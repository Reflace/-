#pragma once

#include <cstdlib>

template <typename T>
int Partition(T* array, int l, int r) {
    T pivot = array[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i >= j) break;
        std::swap(array[i++], array[j--]);
    }
    return j;
}

template <typename T>
void QuickSort(T* array, int l, int r) {
    if (l < r) {
        int q = Partition(array, l, r);
        QuickSort(array, l, q);
        QuickSort(array, q + 1, r);
    }
}

template <typename T>
void QuickSortModified(T* array, int l, int r) {
    T pivot = array[r];
    if (r <= l) return;
    int i = l;
    int j = r - 1;
    int p = l - 1;
    int q = r;
    while (i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i >= j) break;
        std::swap(array[i], array[j]);
        if (array[i] == pivot) {
            p++;
            std::swap(array[p], array[i]);
        }
        i++;
        if (array[j] == pivot) {
            q--;
            std::swap(array[q], array[j]);
        }
        j--;
    }
    std::swap(array[i], array[r]);
    j = i - 1;
    i++;
    for (int k = l; k <= p; k++, j--)
        std::swap(array[k], array[j]);
    for (int k = r - 1; k >= q; k--, i++)
        std::swap(array[k], array[i]);
    QuickSortModified(array, l, j);
    QuickSortModified(array, i, r);
}

// Cлияние массива A, содержащего nA элементов, 
// и массива B, содержащего nB элементов. 
// Результат в массив C. 
template <typename T> 
void Merge(T* A, int nA, T* B, int nB, T* C) { 
    int a = 0;
    int b = 0;
    while (a + b < nA + nB) { 
        if ((b >= nB) || ((a < nA) && (A[a] <= B[b]))) { 
            C[a + b] = A[a]; 
            a++; 
        } else { 
            C[a + b] = B[b]; 
            b++; 
        } 
    } 
}

template <typename T> 
void MergeSort(T* A, int n) { 
    T* B = new T[n]; 
    for (int size = 1; size < n; size *= 2) { 
        //Перебираем все размеры кусочков для слияния: 1,2,4,8... 
        int start = 0;
        for (; start + size < n; start += size * 2) { 
            Merge(A + start, size, A + start + size, std::min(size, n - start - size), B + start); 
        } //Если последний кусочек остался без пары, просто копируем его из A в B: 
        for (; start < n; start++) B[start] = A[start]; 
        T* temp(B); 
        B = A; 
        A = temp;
    } 
}

template<class T> 
void MergeSortRecursive(T* A, int n) {
    if (n < 2) return; 
    if (n == 2) {
        if (A[0] > A[1]) { 
             std::swap(A[0], A[1]);
        } return; 
    } 
    MergeSortRecursive(A , n / 2); //Сортируем первую половину 
    MergeSortRecursive(A + n / 2, n - n / 2); //Сортируем вторую половину 
    T* B = new T[n];
    Merge<T>(A, n / 2, A + (n / 2), n - n / 2, B);
    for (int i = 0; i < n; i++) A[i] = B[i]; 
    delete[] B;
}