#include "predict.hpp"

using namespace std;

// uniform
const int64_t range = 1000000;
double predictIndex(sortData data) {
    return (double)data.num / range + next_normal(0, 0.01);
    //return (double)data.num / range;
}