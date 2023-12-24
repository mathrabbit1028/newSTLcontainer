#ifndef STLALGOS_H
#define STLALGOS_H

#include <bits/stdc++.h>
#include "container.hpp"
#include "../util/util.h"
#include "../Struct.hpp"

using namespace std;

typedef int (*sortfn_t)(vector<sortData>*, int64_t);

int _CountingSort(vector<sortData>* arr, size_t st, size_t ed);
int CountingSort(vector<sortData>* arr, int64_t data_size);
int _MergeSort(vector<sortData>* arr, size_t st, size_t ed);
int MergeSort(vector<sortData>* arr, int64_t data_size);
int _RandQS(vector<sortData>* arr, size_t st, size_t ed);
int RandQS(vector<sortData>* arr, int64_t data_size);
int _RadixSort(vector<sortData>* arr, size_t st, size_t ed);
int RadixSort(vector<sortData>* arr, int64_t data_size);
int _TimSort(vector<sortData>* arr, size_t st, size_t ed);
int TimSort(vector<sortData>* arr, int64_t data_size);
int InsertionSort(vector<sortData>* arr, int st, int ed);
int _RandQSIns(vector<sortData>* arr, size_t st, size_t ed);
int RandQSIns(vector<sortData>* arr, int64_t data_size);
int _IndexSort(vector<sortData>* arr, size_t st, size_t ed);
int IndexSort(vector<sortData>* arr, int64_t data_size);
int Csort(vector<sortData>* arr, int64_t data_size);

#endif