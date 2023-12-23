#include "util/util.h"
#include "NNsort/container.hpp"
#include <bits/stdc++.h>

using namespace std;

int main() {
    newVector<sortData> vec;
    for (int i = 0; i < 5; i++) vec.push_back((sortData) {i, "asdf"});
    vec.Csort();
}