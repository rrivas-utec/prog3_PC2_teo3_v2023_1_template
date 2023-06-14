//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_PC2_TEO3_V2023_1_PARALLEL_PRODUCT_H
#define PROG3_PC2_TEO3_V2023_1_PARALLEL_PRODUCT_H

#include <thread>
#include <vector>
using namespace std;

template<
        template<typename...> class ResultContainer = vector,
        typename FirstIterator,
        typename SecondIterator,
        typename T = typename FirstIterator::value_type
        >
ResultContainer<T>
parallel_product(
        FirstIterator f_start,
        FirstIterator f_stop,
        SecondIterator s_start,
        SecondIterator s_stop) {
    if (distance(f_start, f_stop) != distance(s_start, s_stop))
        throw runtime_error("containers must have same size");
    auto sz = distance(f_start, f_stop);
    auto nh = thread::hardware_concurrency();
    auto range = sz / nh;
    ResultContainer<T> result(sz);

    auto product = [](auto f_start, auto f_stop, auto s_start, auto r_start) {
        while (f_start != f_stop) {
            *r_start = (*f_start) * (*s_start);
            ++r_start; ++f_start; ++s_start;
        }
    };
    vector<thread> vh(nh);
    auto rf_start = f_start;
    auto rs_start = s_start;
    auto rr_start = begin(result);
    for (int i = 0; i < nh; ++i) {
        if (i == nh - 1) range = distance(rf_start, f_stop);
        auto rf_stop = next(rf_start, range);
        auto rs_stop = next(rs_start, range);
        auto rr_stop = next(rr_start, range);
        vh[i] = thread(product, rf_start, rf_stop, rs_start, rr_start);
        rf_start = rf_stop;
        rs_start = rs_stop;
        rr_start = rr_stop;
    }
    for (auto& t: vh) {
        t.join();
    }
    return result;
}



#endif //PROG3_PC2_TEO3_V2023_1_PARALLEL_PRODUCT_H
