#ifndef ALGOS_H
#define ALGOS_H

#include <cstdint>
#include "../Struct.hpp"

int _CountingSort(sortData *arr, size_t st, size_t ed);
int CountingSort(sortData *arr, int64_t data_size);
int _MergeSort(sortData *arr, size_t st, size_t ed);
int MergeSort(sortData *arr, int64_t data_size);
int QuickSort(sortData *arr, int64_t data_size);
int _RandQS(sortData *arr, size_t st, size_t ed);
int RandQS(sortData *arr, int64_t data_size);
int _RadixSort(sortData *arr, size_t st, size_t ed);
int RadixSort(sortData *arr, int64_t data_size);
int TimSort(sortData *arr, int64_t data_size);
int InsertionSort(sortData *arr, int st, int ed);
int _RandQSIns(sortData *arr, size_t st, size_t ed);
int RandQSIns(sortData *arr, int64_t data_size);
int _IndexSort(sortData *arr, size_t st, size_t ed);
int IndexSort(sortData *arr, int64_t data_size);

#endif