//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_PC2_TEO3_V2023_1_SPLIT_RANGE_H
#define PROG3_PC2_TEO3_V2023_1_SPLIT_RANGE_H

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

template <
    template<typename...> class SourceContainer,
    typename T
>
vector<SourceContainer<T>>
split_range(SourceContainer<T>& cnt, initializer_list<int> il) {
    auto n = accumulate(begin(il), end(il), 0);
    if (n != distance(begin(cnt), end(cnt)))
        throw runtime_error("range is greater than container size.");

    vector<SourceContainer<T>> result;
    result.reserve(n);
    auto r_start = begin(cnt);
    for (const auto& item: il) {
        auto r_stop = next(r_start, item);
        result.emplace_back(r_start, r_stop);
        r_start = r_stop;
    }
    return result;
}



#endif //PROG3_PC2_TEO3_V2023_1_SPLIT_RANGE_H
