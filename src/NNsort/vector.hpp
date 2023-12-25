#ifndef VECTOR_H
#define VECTOR_H

#include <bits/stdc++.h>
#include "predict.hpp"
#include "STLalgos.hpp"
#include "Algos.hpp"
using namespace std;

template <typename T>
class newVector {
private:
    static constexpr size_t DEFAULT_CAP = 32;
    T* arr;
    size_t _size;
    size_t _capacity;
public:
    newVector(size_t cap = DEFAULT_CAP) : arr((T*) malloc(sizeof(T) * cap)), _size(0), _capacity(cap) {};
    newVector(const newVector& v) : arr((T*) malloc(sizeof(T) * v._capacity)), _size(v._size), _capacity(v._capacity) {
        for (size_t i = 0; i < _size; i++)
            arr[i] = v[i];
    }
    newVector(newVector&& v) : arr(move(v.arr)), _size(move(v._size)), _capacity(move(v._capacity)) {
        v.arr = nullptr;
        v.m_size = 0;
        v.m_capacity = 0;
    }

    ~newVector() { free(arr); }

    T* begin() const { return arr; }

    T* end() const { return arr + _size; }

    T& front() { return arr[0]; }
    const T& front() const { return arr[0]; }

    T& back() { return arr[_size - 1]; }
    const T& back() const { return arr[_size - 1]; }

    T& operator[](size_t idx) { return arr[idx]; }
    const T& operator[](size_t idx) const { return arr[idx]; }

    size_t capacity() const { return _capacity; }
    size_t size() const { return _size; }
    bool empty() const { return _size == 0; }
    void clear() { _size = 0; }

    void push_back(const T& val) {
        if (_size >= _capacity) {
            if (_capacity < DEFAULT_CAP) _capacity = DEFAULT_CAP;
            else _capacity *= 2;
            arr = (T*) realloc(arr, sizeof(T) * _capacity);
        }
        arr[_size++] = val;
    }
    void push_back(T&& val) {
        if (_size >= _capacity) {
            if (_capacity < DEFAULT_CAP) _capacity = DEFAULT_CAP;
            else _capacity *= 2;
            arr = (T*) realloc(arr, sizeof(T) * _capacity);
        }
        arr[_size++] = std::move(val);
    }

    void pop_back() { _size = _size > 0 ? _size - 1 : 0; }

    void _Csort(size_t st, size_t ed) {
        const constexpr size_t b = (1<<2);
        size_t* index = (size_t*) malloc(sizeof(size_t) * _capacity);
        size_t* count = (size_t*) malloc(sizeof(size_t) * b);
        T* result = (T*) malloc(sizeof(T) * _capacity);
        for (size_t i = 0; i < b; i++) count[i] = 0;
        for (size_t i = st; i < ed; i++) {
            index[i] = (size_t)(predictIndex(arr[i]) * b);
            count[index[i]]++;
        }
        for (size_t i = 1; i < b; i++)
            count[i] = count[i] + count[i - 1];
        for (size_t i = st; i < ed; i++)
            result[--count[index[i]] + st] = arr[i];
        for (size_t i = 0; i < b; i++)
            _MergeSort(result, st + count[i], i+1>=b ? ed : (st + count[i + 1]));
        for (size_t i = st + count[0]; i < st + count[1]; i++) {
            cout << result[i].num << " ";
        }

        InsertionSort(result, st, ed);
        free(arr);
        arr = result;
        free(index);
        free(count);
    }
    void Csort(void) {
        _Csort(0, _size);
    }

    size_t lower_bound(size_t st, size_t ed, T data) {
        size_t index = (size_t)(predictIndex(data) * (this->size()));
        while (index < ed && arr[index] < data) index++;
        while (index > st && arr[index-1] >= data) index--;
        return index;
    }
};

#endif