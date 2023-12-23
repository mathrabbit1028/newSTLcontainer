#pragma once

struct sortData {
    int64_t num;
    char dummy[64];

    bool operator<(const sortData& other) const {
        return num < other.num;
    }

    bool operator>(const sortData& other) const {
        return num > other.num;
    }

    bool operator<=(const sortData& other) const {
        return num <= other.num;
    }

    bool operator>=(const sortData& other) const {
        return num >= other.num;
    }

    bool operator==(const sortData& other) const {
        return num == other.num;
    }

    bool operator!=(const sortData& other) const {
        return num != other.num;
    }
};