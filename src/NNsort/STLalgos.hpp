#ifndef STLALGOS_H
#define STLALGOS_H

#include <bits/stdc++.h>
#include "container.hpp"
#include "../util/util.h"
#include "../Struct.hpp"

using namespace std;

typedef int (*sortfn_t)(vector<sortData>*, int64_t);

int _stlCountingSort(vector<sortData>* arr, size_t st, size_t ed);
int stlCountingSort(vector<sortData>* arr, int64_t data_size);
int _stlMergeSort(vector<sortData>* arr, size_t st, size_t ed);
int stlMergeSort(vector<sortData>* arr, int64_t data_size);
int _stlRandQS(vector<sortData>* arr, size_t st, size_t ed);
int stlRandQS(vector<sortData>* arr, int64_t data_size);
int _stlRadixSort(vector<sortData>* arr, size_t st, size_t ed);
int stlRadixSort(vector<sortData>* arr, int64_t data_size);
int _stlTimSort(vector<sortData>* arr, size_t st, size_t ed);
int stlTimSort(vector<sortData>* arr, int64_t data_size);
int stlInsertionSort(vector<sortData>* arr, int st, int ed);
int _stlRandQSIns(vector<sortData>* arr, size_t st, size_t ed);
int stlRandQSIns(vector<sortData>* arr, int64_t data_size);
int _stlIndexSort(vector<sortData>* arr, size_t st, size_t ed);
int stlIndexSort(vector<sortData>* arr, int64_t data_size);

#endif