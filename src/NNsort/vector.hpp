#ifndef VECTOR_H
#define VECTOR_H

#include <bits/stdc++.h>
#include "predict.hpp"
#include "STLalgos.hpp"
using namespace std;

template <typename T>
class newVector : public vector<T> {
private:

public:
    void _Csort(size_t st, size_t ed) {
        return;
        vector<size_t> index(this->size(), 0);
        vector<size_t> count(this->size(), 0);
        vector<T> result(this->size(), T());
        for (size_t i = st; i < ed; i++) {
            index[i] = (size_t)(predictIndex((*this)[i]) * (this->size()));
            index[i] = min(index[i], ed - 1);
            index[i] = max(index[i], st);
            count[index[i]]++;
        }
        for (size_t i = st + 1; i < ed; i++)
            count[i] = count[i] + count[i - 1];
        for (size_t i = st; i < ed; i++)
            result[--count[index[i]] + st] = (*this)[i];
        //InsertionSort(&result, st, ed);
        _TimSort(&result, st, ed);
        for (size_t i = st; i < ed; i++)
            (*this)[i] = result[i];
    }
    void Csort(void) {
        _Csort(0, this->size());
    }
};

#endif