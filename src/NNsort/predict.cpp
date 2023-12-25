#include "predict.hpp"

using namespace std;

// uniform
const int64_t range = 1000000;
double predictIndex(sortData data) {
    return (double)data.num / range;
}