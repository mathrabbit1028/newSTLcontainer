#include "NNsort/container.hpp"
#include <bits/stdc++.h>
#include "util/util.h"

using namespace std;

int main(int argc, char **argv) {

    int64_t data_size, data_range;
    size_t iter_count = 100;
    sscanf(argv[1], "%lld", &data_size);
    sscanf(argv[2], "%lld", &data_range);
    if (argv[3] != NULL) sscanf(argv[3], "%lld", &iter_count);

    const sortfn_t fn_ptr[] = {Csort, MergeSort, RandQSIns, IndexSort, RadixSort};
    const char* fn_name[] = {"   Csort",
                             "   merge",
                             "  randQS",
                             "   Index",
                             "   Radix"};
    const int fn_cnt = sizeof(fn_name) / sizeof(fn_name[0]);
    vector<double> res[fn_cnt];

    for (size_t t = 0; t < iter_count; t++) {
        system("cls");
        printf("[");
        for (size_t k = 0; k < (t * 20) / iter_count; k++) printf(">");
        for (size_t k = (t * 20) / iter_count; k < 20; k++) printf("=");
        printf("] ( %03lld / %03lld )\n", t, iter_count);

        uint64_t seeds[4];
        set_seed_secure(seeds);

        newVector<sortData> newArr;
        set_seed_manual(seeds);
        for (size_t i = 0; i < data_size; i++) {
            newArr.push_back(sortData());
            newArr[i].num = next_r(0, data_range);
            //arr[i].num = (int64_t)next_normal(0, data_range/10);
            for (size_t j = 0; j < 63; j++) newArr[i].dummy[j] = next_r(0, 10) + '0';
            newArr[i].dummy[63] = '\0';
        }
        double st, ed;
        st = GetTicks();
        Csort(&newArr, data_size);
        ed = GetTicks();
        res[0].push_back((double)(ed - st) / GetFreq());

        vector<sortData> arr(data_size, sortData());
        for (size_t i = 1; i < fn_cnt; i++) {
            set_seed_manual(seeds);
            for (size_t i = 0; i < data_size; i++) {
                arr[i].num = next_r(0, data_range);
                //arr[i].num = (int64_t)next_normal(0, data_range/10);
                for (size_t j = 0; j < 63; j++) arr[i].dummy[j] = next_r(0, 10) + '0';
                arr[i].dummy[63] = '\0';
            }
            double st, ed;
            st = GetTicks();
            fn_ptr[i](&arr, data_size);
            ed = GetTicks();
            res[i].push_back((double)(ed - st) / GetFreq());
        }
    }
    
    printf("n : %lld / k : %lld\n", data_size, data_range);
    for (size_t i = 0; i < fn_cnt; i++) {
        double mean = 0, stdev = 0;
        for (int j = 0; j < iter_count; j++) mean += res[i][j];
        mean /= iter_count;
        for (int j = 0; j < iter_count; j++) stdev += pow(res[i][j] - mean, 2);
        stdev /= iter_count;
        stdev = pow(stdev, 0.5);
        printf("%10s : %10.7f (%.7f)\n", fn_name[i], mean, stdev);
    }

    return 0;
}