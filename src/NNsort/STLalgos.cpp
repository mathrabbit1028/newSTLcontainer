#include "STLalgos.hpp"

using namespace std;


int _CountingSort(vector<sortData> arr, size_t st, size_t ed) {
    int64_t _min = 0;
    int64_t _max = 0;

    for (size_t i = st; i < ed; i++) {
        if (i == st) {
            _min = arr[i].num;
            _max = arr[i].num;
        } else {
            if (arr[i].num < _min) _min = arr[i].num;
            if (arr[i].num > _max) _max = arr[i].num;
        }
    }
    
    vector< vector<sortData> > cnt(_max - _min + 1, vector<sortData>());

    // cout << "MIN = " << _min << ", MAX = " << _max << '\n';

    for (size_t i = st; i < ed; i++) {
        cnt[arr[i].num - _min].push_back(arr[i]);
    }

    size_t idx = st;

    for (size_t i = 0; i < _max - _min + 1; i++) {
        for (size_t j = 0; j < cnt[i].size(); j++) {
            arr[idx] = cnt[i][j];
            idx++;
        }
    }

    return 0;
}


int CountingSort(vector<sortData> arr, int64_t data_size) {
    _CountingSort(arr, 0, data_size);

    return 0;
}


int _MergeSort(vector<sortData> arr, size_t st, size_t ed) {
    if (st == ed) {
        return 0;
    } else if (st + 1 == ed) {
        if (arr[st].num <= arr[ed].num) {
            return 0;
        } else {
            swap(arr[st], arr[ed]);
            return 0;
        }
    } else if (st + 16 > ed) {
        InsertionSort(arr, st, ed);
        return 0;
    } else {
        size_t mid = (st + ed) / 2;

        _MergeSort(arr, st, mid);
        _MergeSort(arr, mid + 1, ed);

        size_t p1 = st;
        size_t p2 = mid + 1;

        while (p1 != mid and p2 != ed) {
            if (arr[p1].num <= arr[p2].num) {
                p1++;
            } else {
                swap(arr[p1].num, arr[p2].num);
                p2++;
            }
        }
        
        return 0;
    }

    return 0;
}


int MergeSort(vector<sortData> arr, int64_t data_size) {
    _MergeSort(arr, 0, data_size);

    return 0;
}


int _RandQS(vector<sortData> arr, size_t st, size_t ed) {
    if (ed - st < 2) return 0;

    int64_t pivot = arr[next_r(st, ed)].num;
    int64_t i, j;

    for (i = st, j = ed - 1; ; i++, j--) {
        while (arr[i].num < pivot) { i++; }
        while (arr[j].num > pivot) { j--; }

        if (i >= j) {
            break;
        }

        swap(arr[i].num, arr[j].num);
    }

    _RandQS(arr, st, i);
    _RandQS(arr, i, ed);

    return 0;
}


#define RANDQSINS_THRESHOLD 16
int _RandQSIns(vector<sortData> arr, size_t st, size_t ed) {
    if (ed - st < RANDQSINS_THRESHOLD)
        return InsertionSort(arr, st, ed);

    int64_t pivot = arr[next_r(st, ed)].num;
    int64_t i, j;

    for (i = st, j = ed - 1; ; i++, j--) {
        while (arr[i].num < pivot) { i++; }
        while (arr[j].num > pivot) { j--; }

        if (i >= j) {
            break;
        }

        swap(arr[i].num, arr[j].num);
    }

    _RandQS(arr, st, i);
    _RandQS(arr, i, ed);

    return 0;
}


int RandQSIns(vector<sortData> arr, int64_t data_size) {
    return _RandQSIns(arr, 0, data_size);
}


int RandQS(vector<sortData> arr, int64_t data_size) {
    _RandQS(arr, 0, data_size);

    return 0;
}


int _RadixSort(vector<sortData> arr, size_t st, size_t ed) {
    const int r = 16;

    int64_t _min = 0;
    int64_t _max = 0;
    for (int i = st; i < ed; i++) {
        if (i == 0) {
            _min = arr[i].num;
            _max = arr[i].num;
        } else {
            if (arr[i].num < _min) _min = arr[i].num;
            if (arr[i].num > _max) _max = arr[i].num;
        }
    }

    if (_max == _min) return 0;

    for (int i = st; i < ed; i++) arr[i].num -= _min;

    double d = log(_max - _min)/log(r);

    for (int i = 0; i <= d; i++) {
        vector<int> cnt[r];
        vector<sortData> res;
        for (int j = st; j < ed; j++) {
            int64_t t = (arr[j].num % (int64_t)pow(r, i+1)) / (int64_t)pow(r, i);
            cnt[t].push_back(j);
        }
        for (int k = 0; k < r; k++) {
            for (int j = 0; j < (int)cnt[k].size(); j++)
                res.push_back(arr[cnt[k][j]]);
        }
        for (int j = st; j < ed; j++) arr[j] = res[j - st];
    }

    for (int i = st; i < ed; i++) arr[i].num += _min;

    return 0;
}


int RadixSort(vector<sortData> arr, int64_t data_size) {
    _RadixSort(arr, 0, data_size);

    return 0;
}

int find_minrun(int64_t data_size) {
    int r = 0;
    while (data_size >= 32) {
        r |= data_size bitand 1;
        data_size >>= 1;
    }
    return data_size + r;
}

int InsertionSort(vector<sortData> arr, int st, int ed) {
    for (int i = st; i < ed; i++) {
        int64_t now = arr[i].num;
        int j = i - 1;
        while (j >= st and now < arr[j].num) {
            arr[j + 1].num = arr[j].num;
            j -= 1;
        }
        arr[j + 1].num = now;
    }

    return 0;
}


int _merge(vector<sortData> arr, int lt, int mid, int rt) {

    vector<sortData> temp;
    int p = lt, q = mid;

    while (true) {
        if (p >= mid and q >= rt) break;
        if (p >= mid) {
            temp.push_back(arr[q]);
            q++;
            continue;
        }
        if (q >= rt) {
            temp.push_back(arr[p]);
            p++;
            continue;
        }
        if (arr[p].num <= arr[q].num) {
            temp.push_back(arr[p]);
            p++;
        }
        else {
            temp.push_back(arr[q]);
            q++;
        }
    }

    for (int i = lt; i < rt; i++) arr[i] = temp[i - lt];

    return 0;
}


int TimSort(vector<sortData> arr, int64_t data_size) {
    int minrun = find_minrun(data_size);

    for (int st = 0; st < data_size; st += minrun) {
        int ed = min(st + minrun, (int)data_size);
        InsertionSort(arr, st, ed);
    }

    int sz = minrun;
    while (sz < data_size) {
        for (int lt = 0; lt < data_size; lt += sz * 2) {
            int mid = min((int)data_size, lt + sz);
            int rt = min(lt + 2 * sz, (int)data_size);
            _merge(arr, lt, mid, rt);
        }
        sz *= 2;
    }

    return 0;
}


int _IndexSort(vector<sortData> arr, size_t st, size_t ed) {
    sort(arr.begin() + st, arr.begin() + ed);
    return 0;
}


int IndexSort(vector<sortData> arr, int64_t data_size) {
    _IndexSort(arr, 0, data_size);
    return 0;
}


int Csort(vector<sortData> arr, int64_t data_size) {
    newVector<sortData> vec;
    for (size_t i = 0; i < data_size; i++) vec.push_back(arr[i]);
    vec.Csort();
    return 0;
}